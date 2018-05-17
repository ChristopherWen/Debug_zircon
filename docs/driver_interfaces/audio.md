# Audio Driver Streaming Interface

This document describes the audio streaming interface exposed by audio drivers
in Zircon.  It is meant to serve as a reference for both users and
driver-authors, and to unambiguously define the interface contract which drivers
must implement and users must follow.

## Overview

Audio streams are device nodes published by driver services intended to be used
by applications in order to capture and/or render audio in a Zircon device.
Each stream in the system (input or output) represents a stream of digital audio
information which may be either received or transmitted by device.  Streams are
dynamic and may created or destroyed by the system at any time.  Which streams
exist at any given point in time, and what controls their lifecycles are
consider to be issues of audio policy and codec management and are not discussed
in this document.  Additionally, the information present in audio outputs
streams is exclusive to the application owner of the stream.  Mixing of audio is
_not_ a service provided by the audio stream interface.

> TODO: extend this interface to support the concept of low-latency hardware
> mixers.

### Basic Vocabulary

Term | Definition
-----|-----------
Sample | A representation of the sound rendered by a single speaker, or captured by a single microphone, at a single instant in time.
LPCM | Linear pulse code modulation.  The specific representation of audio samples present in all Zircon uncompressed audio streams.  LPCM audio samples are representations of the amplitude of the audio signal at an instant in time where the numeric values of the encoded audio are linearly distributed across the amplitude levels of the rendering or capture device.  This is in contrast to A-law and &mu;-law encodings which have non-linear mappings from numeric value to amplitude level.
Channel | Within an audio stream, the subset of information which will be rendered by a single speaker, or which was captured by a single microphone in a stream.
Frame | A set of audio samples for every channel of a audio stream captured/rendered at a single instant in time.
Frame Rate | a.k.a. "Sample Rate".  The rate (in Hz) at which audio frames are produced or consumed.  Common sample rates include 44.1 KHz, 48 KHz, 96 KHz, and so on.

> TODO: do we need to extend this interface to support non-linear audio sample
> encodings?  This may be important for telephony oriented microphones which
> deliver &mu;-law encoded samples.

### Basic Operation

Communication with an audio stream device is performed using messages sent over
a [channel](../objects/channel.md).  Applications open the device node for a
stream and obtain a channel by issuing an ioctl.  After obtaining the channel,
the device node may be closed.  All subsequent communication with the stream
will occur using channels.

The "stream" channel will then be used for most command and control tasks
including.
 * Capability interrogation
 * Format negotiation
 * Hardware gain control
 * Determining outboard latency.
 * Plug detection notification.
 * Access control capability detection and signalling
 * Policy level stream purpose indication/Stream Association (TBD)

> TODO: Should plug/unplug detection be done by sending notifications over the
> stream channel, or by publishing/unpublishing the device nodes (and closing
> all channels in the case of unpublished channels)

In order to actually send or receive audio information on the stream, the
specific format to be used must first be set.  The response to a successful
SetFormat operation will contain a new "ring-buffer" channel.  The ring-buffer
channel may be used to request a shared buffer from the stream (delivered in the
form of a [VMO](../objects/vm_object.md)) which may be mapped into the address
space of the application and used to send or receive audio data as appropriate.
Generally, the operations conducted over the ring buffer channel include...
 * Requesting a shared buffer
 * Starting and Stopping stream playback/capture
 * Receiving notifications of playback/capture progress
 * Receiving notifications of error conditions such as HW FIFO under/overflow,
   bus transaction failure, etc...
 * Receiving clock recovery information in the case that the audio output clock
   is based on a different oscillator than the oscillator which backs
   [ZX_CLOCK_MONOTONIC](../syscalls/clock_get.md)

## Operational Details

### Protocol definition

In order to use the C API definitions of the
[audio](../../system/public/zircon/device/audio.h) protocol, applications and
drivers simply say
```C
#include <device/audio.h>
```

### Device nodes

Audio stream device nodes **must** be published by drivers using the protocol
preprocessor symbol given in the table below.  This will cause stream device
nodes to be published in the locations given in the table.  Applications can
monitor these directories in order to discover new streams as they are published
by the drivers.

Stream Type | Protocol | Location
------------|----------|---------
Input | `ZX_PROTOCOL_AUDIO_INPUT` | /dev/class/audio-input
Output | `ZX_PROTOCOL_AUDIO_OUTPUT` | /dev/class/audio-output

### Establishing the stream channel

After opening the device node, client applications may obtain a stream channel
for subsequent communication using the `AUDIO_IOCTL_GET_CHANNEL` ioctl.  For
example...
```C
zx_handle_t OpenStream(const char* dev_node_path) {
    zx_handle_t ret = ZX_HANDLE_INVALID;
    int fd = open(dev_node_path, O_RDONLY);

    if (fd < 0) {
        LOG("Failed to open \"%s\" (res %d)\n", dev_node_path, fd);
        return ret;
    }

    ssize_t res = fdio_ioctl(fd, AUDIO_IOCTL_GET_CHANNEL,
                             nullptr, 0,
                             &ret, sizeof(ret));
    close(fd);

    if (res != ZX_OK)
        printf("Failed to obtain channel (res %zd)\n", res);

    return ret;
}
```

### Client side termination of the stream channel

Clients **may** terminate the connection to the stream at any time simply by
calling [zx_handle_close(...)](../syscalls/handle_close.md) on the stream
channel.  Drivers **must** close any active ring-buffer channels established
using this stream channel and **must** make every attempt to gracefully quiesce
any on-going streaming operations in the process.

### Sending and receiving messages on the stream and ring-buffer channels

All of the messages and message payloads which may be sent or received over
stream and ring buffer channels are defined in the
[audio](../../system/public/zircon/device/audio.h) protocol header.  Messages
may be sent to the driver using the
[zx_channel_write(...)](../syscalls/channel_write.md) syscall.  If a response is
expected, it may be read using the
[zx_channel_read(...)](../syscalls/channel_read.md) syscall.  Best practice,
however, is to queue packets for your [channel(s)](../objects/channel.md)
[port](../objects/port.md) using the
[zx_port_queue(...)](../syscalls/port_queue.md) syscall, and use the
[zx_port_wait(...)](../syscalls/port_wait.md) syscall to determine when your set
of channels have messages (either expected responses or asynchronous
notifications) to be read.

All messages either sent or received over stream an ring buffer channels are
prefaced with an `audio_cmd_hdr_t` structure which contains a 32-bit
transaction ID and an `audio_cmd_hdr_t` enumeration value indicating the
specific command being requested by the application, the specific command being
responded to by the driver, or the asynchronous notification being delivered by
the driver to the application.

When sending a command to the driver, applications **must** place a transaction
ID in the header's `transaction_id` field which is not equal to
`AUDIO_INVALID_TRANSACTION_ID`.  If a response to a command needs to be sent by
the driver to the application, the driver **must** use the transaction ID and
`audio_cmd_t` values sent by the client during the request.  When sending
asynchronous notification to the application, the driver **must** use
`AUDIO_INVALID_TRANSACTION_ID` as the transaction ID for the message.
Transaction IDs may be used by clients for whatever purpose they desire, however
if the IDs are kept unique across all transactions in-flight, the
[zx_channel_call(...)](../syscalls/channel_call.md) may be used to implement a
simple synchronous calling interface.

### Validation requirements

All drivers **must** validate requests and enforce the protocol described above.
In case of any violation, drivers **should** immediately quiesce their hardware
and **must** close the channel, terminating any operations which happen to be in
flight at the time.  Additionally, they **may** log a message to a central
logging service to assist in application developers in debugging the cause of
the protocol violation.  Examples of protocol violation include...
 * Using `AUDIO_INVALID_TRANSACTION_ID` as the value of `message.hdr.transaction_id`
 * Using a value not present in the `audio_cmd_t` enumeration as the value of `message.hdr.cmd`
 * Supplying a payload whose size does not match the size of the request payload for a given
   command.

## Format Negotiation

### Sample Formats

Sample formats are described using the `audio_sample_format_t` type.  It is a
bitfield style enumeration which describes either the numeric encoding of the
uncompressed LPCM audio samples as they reside in memory, or indicating that the
audio stream consists of a compressed bitstream instead of uncompressed LPCM
samples.  Refer to the [audio](../../system/public/zircon/device/audio.h)
protocol header for exact symbol definitions.

Notes
 * With the exception of FORMAT_BITSTREAM, samples are always assumed to
   use linear PCM encoding.  BITSTREAM is used for transporting compressed
   audio encodings (such as AC3, DTS, and so on) over a digital interconnect
   to a decoder device somewhere outside of the system.
 * Be default, multi-byte sample formats are assumed to use host-endianness.
   If the INVERT_ENDIAN flag is set on the format, the format uses the
   opposie of host endianness.  eg. A 16 bit little endian PCM audio format
   would have the INVERT_ENDIAN flag set on it in a when used on a big endian
   host.  The INVERT_ENDIAN flag has no effect on COMPRESSED, 8BIT or FLOAT
   encodings.
 * The 32BIT_FLOAT encoding uses specifically the IEE 754 floating point
   representation.
 * Be default, non-floating point PCM encodings are assumed expressed using
   2s compliment signed integers.  eg. the bit values for a 16 bit PCM sample
   format would range from [0x8000, 0x7FFF] with 0x0000 represting zero
   speaker deflection.  If the UNSIGNED flag is set on the format, the bit
   values would range from [0x0000, 0xFFFF] with 0x8000 representing zero
   deflection.
 * When used to set formats, exactly one non-flag bit **must** be set.
 * When used to describe supported formats, any number of non-flag bits **may**
   be set.  Flags (when present) apply to all of the relevant non-flag bits in
   the bitfield.  eg.  If a stream supports COMPRESSED, 16BIT and 32BIT_FLOAT, and
   the UNSIGNED bit is set, it applies only to the 16BIT format.
 * When encoding a smaller sample size in a larger container (eg 20 or 24bit
   in 32), the most significant bits of the 32 bit container are used while
   the least significant bits should be zero.  eg. a 20 bit sample would be
   mapped onto the range [12,32] of the 32 bit container.

> TODO: can we make the claim that the LSBs will be ignored, or do we have to
> require that they be zero?

> TODO: describe what 20-bit packed audio looks like in memory.  Does it need to
> have an even number of channels in the overall format?  Should we strike it
> from this list if we cannot find a piece of hardware which demands this format
> in memory?

### Enumeration of supported formats

In order to determine the formats supported by a given audio stream,
applications send an `AUDIO_STREAM_CMD_GET_FORMATS` message over the stream
channel.  No additional parameters are required.  Drivers **must** respond to
this request using one or more `audio_stream_cmd_get_formats_resp_t` messages,
even if only to report that there are no formats currently supported.

### Range structures

Drivers indicate support for formats by sending messages containing zero or more
`audio_stream_format_range_t` structures.  Each structure contains field which
describe...
 * A bitmask of supported sample formats.
 * A minimum and maximum number of channels.
 * A set of frame rates.

A single range structure indicates support for each of the combinations of the
three different sets of values (sample formats, channel counts, and frame
rates).  For example, if a range structure indicated support for...
 * 16 bit signed LPCM samples
 * 48000, and 44100 Hz frame rates
 * 1 and 2 channels

Then the fully expanded set of supported formats indicated by the range
structure would be...
 * Stereo 16-bit 48 KHz audio
 * Stereo 16-bit 44.1 KHz audio
 * Mono 16-bit 48 KHz audio
 * Mono 16-bit 44.1 KHz audio

See the Sample Formats section (above) for a description of how sample formats
are encoded in the `sample_formats` member of a range structure.

Supported channel counts are indicated using a pair of min/max channels fields
which indicate an exclusive range of channel counts which apply to this range.
For example, a min/max channels range of [1, 4] would indicate that this audio
stream supports 1, 2, 3 or 4 channels.  A range of [2, 2] would indicate that
this audio stream supports only stereo audio.

Supported frame rates are signalled similarly to channel counts using a pair of
min/max frame per second fields along with a flags field.  While the min/max
values provide an inclusive range of frame rates, the flags determine how to
interpret this range.  Currently defined flags include...
Flag | Definition
-----|-----------
`ASF_RANGE_FLAG_FPS_CONTINUOUS` | The frame rate range is continuous.  All frame rates in the range [min, max] are valid.
`ASF_RANGE_FLAG_FPS_48000_FAMILY` | The frame rate range includes the members of the 48 KHz family which exist in the range [min, max]
`ASF_RANGE_FLAG_FPS_44100_FAMILY` | The frame rate range includes the members of the 44.1 KHz family which exist in the range [min, max]

So, conceptually, the valid frame rates are the union of the sets produced by
applying each of the flags which are set to the inclusive [min, max] range.  For
example, if both the 48 KHz and 44.1 KHz were set, and the range given was
[16000, 47999], then the supported frame rates for this range would be
 * 16000 Hz
 * 22050 Hz
 * 32000 Hz
 * 44100 Hz

The official members of the 48 KHz and 44.1 KHz families are
Family | Frame Rates
-------|------------
`ASF_RANGE_FLAG_FPS_48000_FAMILY` | 8000 16000 32000 48000 96000 192000 384000 768000
`ASF_RANGE_FLAG_FPS_44100_FAMILY` | 11025 22050 44100 88200 176400

Drivers **must** set at least one of the flags, or else the set of supported
frame rates is empty and there was no reason to transmit this range structure.
Also note that the set of valid frame rates is the union of the frame rates
produce by applying each of the set flags.  This implies that there is never any
good reason to set the `ASF_RANGE_FLAG_FPS_CONTINUOUS` in conjunction with any
of the other flags.  While it is technically legal to do so, drivers **should**
avoid this behavior.

### Transporting range structures

Range structures are transmitted from drivers to applications using the
`audio_stream_cmd_get_formats_resp_t` message.  Because of the large number of
formats which may be supported by a stream, drivers may need to send multiple
messages in order to enumerate all available modes.  Messages include the
following fields.
 * A standard `audio_cmd_hdr_t` header.  **All** messages involved in the
   response to an application request **must** use the transaction ID of the
   original request, and **must** set the cmd field of the header to
   `AUDIO_STREAM_CMD_GET_FORMATS`.
 * A `format_range_count` field.  This indicates the total number of format
   range structures which will be sent in this response to the application.
   This number **must** be present in **all** messages involved in the response,
   and **must not** change from message to message.
 * A `first_format_range_ndx` field indicating the zero-based index of the first
   format range being specified in this particular message.  See below for
   details.
 * An array of `audio_stream_cmd_get_formats_resp_t` structures which is at most
   `AUDIO_STREAM_CMD_GET_FORMATS_MAX_RANGES_PER_RESPONSE` elements long.

Drivers **must**
 * Always transmit all of the available audio format ranges.
 * Always transmit the available audio format ranges in ascending index order.
 * Always pack as many ranges as possible in the fixed size message structure.
 * Never overlap index regions or leave gaps.

Given these requirements, if the maximum number of ranges per response were 15,
and a driver needed to send 35 ranges in response to an application's request,
then 3 messages in total would be needed, and the `format_range_count` and
`first_format_range_ndx` fields for each message would be as follows.
Msg # | `format_range_count` | `first_format_range_ndx`
------|----------------------|-------------------------
1 | 35 | 0
2 | 35 | 15
3 | 35 | 30

`first_format_range_ndx` **must** never be greater than `format_range_count`,
however `format_range_count` **may** be zero if an audio stream currently
supports no formats.  The total number of `audio_stream_format_range_t`
structures in an `audio_stream_cmd_get_formats_resp_t` message is given by the
formula

```C
valid_ranges = MIN(AUDIO_STREAM_CMD_GET_FORMATS_MAX_RANGES_PER_RESPONSE,
                   msg.format_range_count - msg.first_format_range_ndx);
```

Drivers **may** choose to always send an entire
`audio_stream_cmd_get_formats_resp_t` message, or to send a truncated message
which ends after the last valid range structure in the `format_ranges` array.
Applications **must** be prepared to receive up to
`sizeof(audio_stream_cmd_get_formats_resp_t) bytes for each message, but also
accept messages as short as `offsetof(audio_stream_cmd_get_formats_resp_t, format_ranges)`

> TODO: how do devices signal a change of supported formats (think, HDMI hotplug
> event)?  Are such devices required to simply remove and republish the device?

> TODO: define how to enumerate supported compressed bitstream formats.

### Setting the desired stream format

In order to select a stream format, applications send an
`AUDIO_STREAM_CMD_SET_FORMAT` message over the stream channel.  In the message,
for uncompressed audio streams, the application specifies
 * The frame rate of the stream in Hz using the `frames_per_second` field (in the
   case of an uncompressed audio stream).
 * The number of channels packed into each frame using the `channels` field.
 * The format of the samples in the frame using the `sample_format` field (see
   Sample Formats, above)

Success or failure, drivers **must** respond to a request to set format using a
`audio_stream_cmd_set_format_resp_t`.

In the case of success, drivers **must** set the `result` field of the response
to `ZX_OK` and **must** return a new ring buffer channel over which streaming
operations will be conducted.  If a previous ring buffer channel had been
established and was still active, the driver **must** close this channel and
make every attempt to gracefully quiesce any on-going streaming operations in
the process.

In the case of failure, drivers **must** indicate the cause of failure using the
`result` field of the message and **must not** simply close the stream channel
as is done for a generic protocol violation.  Additionally, they **may** choose
to preserve a pre-existing ring-buffer channel, or to simply close such a
channel as is mandated for a successful operation.

> TODO: specify how compressed bitstream formats will be set

## Hardware Gain Control

### Hardware gain control capability reporting

In order to determine a stream's gain control capabilities, applications send an
`AUDIO_STREAM_CMD_GET_GAIN` message over the stream channel.  No parameters
need to be supplied with this message.  All stream drivers **must** respond to
this message, regardless of whether or not the stream hardware is capable of any
gain control.  All gain values are expressed using 32 bit floating point numbers
expressed in dB.

Drivers respond to this message with values which indicate the current gain
settings of the stream, as well as the stream's gain control capabilities.
Current gain settings are expressed using a bool/float tuple indicating if the
stream is currently muted or not along with the current dB gain of the stream.
Gain capabilities consist of bool and 3 floats.  The bool indicates whether or
not the stream can be muted.  The floats give the minimum and maximum gain
settings, along with the `gain step size`.  The `gain step size` indicates the
smallest increment with which the gain can be controlled counting from the
minimum gain value.

For example, an amplifier which has 5 gain steps of 7.5 dB each and a maximum
0 dB gain would indicate a range of (-30.0, 0.0) and a step size of 7.5.
Amplifiers capable of functionally continuous gain control **may** encode their
gain step size as 0.0.

Regardless of mute capabilities, drivers for fixed gain streams **must** report
their min/max gain as (0.0, 0.0).  The gain step size is meaningless in this
situation, but drivers **should** report their step size as 0.0.

### Setting hardware gain control levels

In order to change a stream's current gain settings, applications send an
`AUDIO_STREAM_CMD_SET_GAIN` message over the stream channel.  Two parameters
are supplied with this message, a set of flags which control the request, and a
float indicating the dB gain which should be applied to the stream.

Three valid flags are currently defined.
 * `AUDIO_SGF_MUTE_VALID`.  Set when the application wishes to set the
   muted/un-muted state of the stream.  Clear if the application wishes to
   preserve the current muted/un-muted state.
 * `AUDIO_SGF_GAIN_VALID`.  Set when the application wishes to set the
   dB gain state of the stream.  Clear if the application wishes to
   preserve the current gain state.
 * `AUDIO_SGF_MUTE`.  Indicates the application's desired mute/un-mute state
   for the stream.  Significant only if `AUDIO_SGF_MUTE_VALID` is also set.

Drivers **must** fail the request with an `ZX_ERR_INVALID_ARGS` result if the
application's request is incompatible with the stream's capabilities.
Incompatible requests include.
 * The requested gain is less than the minimum support gain for the stream.
 * The requested gain is more than the maximum support gain for the stream.
 * Mute was requested, but the stream does not support an explicit mute.

Presuming that the request is valid, drivers **should** round the request to the
nearest supported gain step size.  For example, if a stream can control its
gain on the range from -60.0 to 0.0 dB, a request to set the gain to -33.3 dB
will result in a gain of -33.5 being applied.  A request for a gain of -33.2 dB
will result in a gain of -33.0 being applied.

Applications **may** choose not to receive an acknowledgement of a SET_GAIN
command by setting the `AUDIO_FLAG_NO_ACK` flag on their command.  No response
message will be sent to the application, regardless of the success or failure of
the command.  If an acknowledgement was requested by the application, drivers
respond with a message indicating the success or failure of the operation as
well as the current gain/mute status of the system (regardless of whether the
request was a success).

## Determining external latency

The external latency of an audio stream is defined as the amount of time it
takes outbound audio to travel from the system's interconnect to the speakers
themselves, or inbound audio to travel from the microphone to the system's
interconnect.  For example, if an external codec connected to the system using a
TDM interconnect introduced a 4 frame delay between reception of a TDM frame and
rendering of the frame at the speakers themselves, the external delay of this
audio path would be 4 audio frames.

External delay is reported in the `external_delay_nsec` field of a successful
`AUDIO_STREAM_CMD_SET_FORMAT` response as a non-negative number of nanoseconds.
Drivers **should** make their best attempt to accurately report the total of all
of the sources of delay the driver knows about.  Information about this delay
can frequently be found in codec data sheets, dynamically reported as properties
of codecs using protocols such as Intel HDA or the USB Audio specifications, or
reported by down stream devices using mechanisms such as EDID when using HDMI or
DisplayPort interconnects.

## Plug Detection

In addition to streams being published/unpublished in response to being
connected or disconnected to/from their bus, streams may have the ability to be
plugged or unplugged at any given point in time.  For example, a set of USB
headphones publish a new output stream when connected to USB, but be "hardwired"
from a plug detection standpoint.  A different USB audio adapter with a standard
3.5mm phono jack might publish an output stream when connected via USB, but
might change its plugged/unplugged state as the user plugs/unplugs devices via
the 3.5mm jack.

The ability to query the currently plugged or unplugged state of a stream, and
to register for asynchonous notifications of plug state changes (if supported)
is handled via plug detection messages.

### AUDIO_STREAM_CMD_PLUG_DETECT

In order to determine a stream's plug detection capabilities, current plug
state, and to enable or disable for asynchronous plug detection notifications,
applications send a `AUDIO_STREAM_CMD_PLUG_DETECT` command over the stream
channel.  Drivers respond with a set of `audio_pd_notify_flags_t`, along with a
timestamp referenced from `ZX_CLOCK_MONOTONIC` indicating the last time the plug
state changed.

Three valid flags are currently defined.
 * `AUDIO_PDNF_HARDWIRED`.  Set when the stream hardware is considered to be
   "hardwired".  In other words, the stream is considered to be connected as
   long as the device is published.  Examples include a set of built in
   speakers, a pair of USB headphones, or a plug-able audio device with no plug
   detect functionality.
 * `AUDIO_PDNF_CAN_NOTIFY`.  Set when the stream hardware is capable of
   asynchronously detecting that a device's plug state has changed and sending a
   notification message if requested by the application.
 * `AUDIO_PDNF_PLUGGED`  Set when the stream hardware considers the
   stream to be currently in the "plugged-in" state.

Drivers for "hardwired" streams **must not** set the `CAN_NOTIFY` flag, and
**must** set the `PLUGGED` flag.  In addition, the plug state time of the
response to the `PLUG_DETECT` message **should** always be set to the time at
which the stream device was published by the driver.

Applications **may** choose not to receive an acknowledgement of a `PLUG_DETECT`
command by setting the `AUDIO_FLAG_NO_ACK` flag on their command.  No response
message will be sent to the application, regardless of the success or failure of
the command.  The most common use for this would be when an application wanted
to disable asynchronous plug state detection messages and was not actually
interested in the current plugged/unplugged state of the stream.

### AUDIO_STREAM_PLUG_DETECT_NOTIFY

Applications may request that streams send them asynchronous notifications of
plug state changes using the flags field of the `AUDIO_STREAM_CMD_PLUG_DETECT`
command.

Two valid flags are currently defined.
 * `AUDIO_PDF_ENABLE NOTIFICATIONS` Set by applications in order to
   request that `AUDIO_STREAM_PLUG_DETECT_NOTIFY`
 * `AUDIO_PDF_DISABLE_NOTIFICATIONS` Set by applications in order to
   stop new `AUDIO_STREAM_PLUG_DETECT_NOTIFY` messages from being sent.

In order to request the current plug state without altering the current
notification enable/disable state, clients simply set neither flag by passing
either 0, or the value `AUDIO_PDF_NONE`.  Clients **should** not set both flags
at the same time.  If they do, drivers **must** interpret this to mean that the
final state of the system should be disabled.

Applications which request asynchronous notifications of plug state changes
**should** always check the `CAN_NOTIFY` flag in the driver response.  Streams
may be capable of plug detection (`HARDWIRED` is not set), but may not be
capable of detecting plug state changes asynchronously.  Applications may still
learn of plug state changes, but will need to do so by polling with repeated
`PLUG_DETECT` commands.  Drivers for streams which do not set the `CAN_NOTIFY`
flag are free to ignore enable/disable notification requests from applications,
and **must** not ever send an `AUDIO_STREAM_PLUG_DETECT_NOTIFY` message.

## Access control capability detection and signaling

> TODO: specify how this works.  In particular, specify how drivers indicate
> to applications support for various digital access control mechanisms such as
> S/PDIF control words and HDCP.

## Stream purpose and association

> TODO: specify how drivers can indicate the general "purpose" of an audio
> stream in the system (if known), as well as its relationship to other streams
> (if known).  For example, an embedded target like a phone or a tablet needs to
> indicate which output stream is the built-in speaker vs. which is the headset
> jack output.  In addition, it needs to make clear which input stream is the
> microphone associated with the headset output vs. the builtin speaker.

## Ring-Buffer Channels

### Overview

Generally speaking, client use the ring-buffer channel to establish a shared
memory buffer, and then start/stop playback/capture of audio stream data.  Once
started, stream consumption/production is assumed to proceed at the nominal rate
from the point in time given in a successful response to the start command,
allowing clients to operate without the need to receive any periodic
notifications about consumption/production position from the ring buffer itself.
Note that the ring-buffer will almost certainly have some form of FIFO buffer
between the memory bus and the audio hardware which causes it to either
read-ahead in the stream (in the case of playback), or potentially hold onto
data (in the case of capturing).  In the case of open-loop operation, it is
important for clients to query the size of this buffer before beginning
operation so they know how far ahead/behind the stream's nominal inferred
read/write position they need to stay in order to prevent audio glitching.

Also note that because of the shared buffer nature of the system, and the fact
that drivers are likely to be DMA-ing directly from this buffer to hardware, it
is important for clients running on architectures which are not automatically
cache coherent to be sure that they have properly written-back their cache after
writing playback data to the buffer, or invalidated their cache before reading
captured data.

### Determining the FIFO depth

Applications determine stream's FIFO depth using the
`AUDIO_RB_CMD_GET_FIFO_DEPTH` command.  Drivers **must** return their FIFO
depth, expressed in bytes, in the `fifo_depth` field of the response.  In order
to ensure proper playback or capture of audio, applications and drivers must be
careful to respect this value.  This is to say that drivers must not read beyond
the nominal playback position of the stream plus this number of bytes when
playing audio stream data.  Applications must stay this number of bytes behind
the nominal capture point of the stream when capturing audio stream data.

Once the format of a stream is set and a ring-buffer channel has been opened,
the driver **must not** change this value.  From an application's point of view,
it is a constant property of the ring-buffer channel.

### Obtaining a shared buffer

Once an application has successfully set the format of a stream, it will receive
a new [channel](../objects/channel.md) representing its connection to the
stream's ring-buffer.  In order to send or receive audio, the application must
first establish a shared memory buffer.  This is done by sending an
`AUDIO_RB_CMD_GET_BUFFER` request over the ring-buffer channel.  This may only
be done while the ring-buffer is stopped.  Applications **must** specify two
parameters when requesting a ring buffer.

#### `min_ring_buffer_frames`
The minimum number of frames of audio the client need allocated for the ring
buffer.  Drivers may need to make this buffer larger in order to meet hardware
requirement.  Clients **must** use the returned VMOs size (in bytes) to determine
the actual size of the ring buffer may not assume that the size of the buffer
(as determined by the driver) is exactly the size they requested.  Drivers
**must** ensure that the size of the ring buffer is an integral number of audio
frames.

> TODO : Is it reasonable to require that driver produce buffers which are an
> integral number of audio frames in length.  It certainly makes the audio
> client's life easier (client code never needs to split or re-assemble a frame
> before processing), but it might make it difficult for some audio hardware to
> meet its requirements without making the buffer significantly larger than the
> client asked for.

#### `notifications_per_ring`
The number of position update notifications (`audio_rb_position_notify_t`) the
client would like the driver to send per cycle through the ring buffer.  Drivers
should attempt to space the notifications as uniformly throughout the ring as
their hardware design allows, but clients may not rely on perfectly uniform
spacing of the update notifications.  Client's are not required to request any
notifications at all and may choose to run using only start time and FIFO depth
information to determine the driver's playout or capture position.

Success or failure, drivers **must** respond to a `GET_BUFFER` request using an
`audio_rb_cmd_get_buffer_resp_t` message.  If the driver fails the request
because a buffer has already been established and the ring-buffer has already
been started, it **must not** either stop the ring-buffer, or discard the
existing shared memory.  If the application requests a new buffer after having
already established a buffer while the ring buffer is stopped, it **must**
consider the existing buffer is has to be invalid.  Success or failure, the old
buffer is now gone.

Upon succeeding, the driver **must** return a handle to a
[VMO](../objects/vm_object.md) with permissions which allow applications to map
the VMO into their address space using [zx_vmar_map](../syscalls/vmar_map.md),
and to read/write data in the buffer in the case of readback, or simply read the
data in the buffer in the case of capture.  Additionally, the driver **must**
report the actual number of frames of audio it will use in the buffer via the
`num_ring_buffer_frames` field of the `audio_rb_cmd_get_buffer_resp_t` message.
This number **may** be larger than the `min_ring_buffer_frames` request from the
client but **must not** be either smaller than this number, nor larger than the
size (when converted to bytes) of the VMO as reported by
[zx_vmo_get_size()](../syscalls/vmo_get_size.md)

### Starting and Stopping the ring-buffer

Clients may request that a ring-buffer start or stop using the
`AUDIO_RB_CMD_START` and `AUDIO_RB_CMD_STOP` commands.  Success or failure,
drivers **must** send a response to these requests.  Attempting to start a
stream which is already started **must** be considered a failure.  Attempting to
stop a stream which is already stopped **should** be considered a success.
Ring-buffers cannot be either stopped or started until after a shared buffer has
been established using the `GET_BUFFER` operation.

Upon successfully starting a stream, drivers **must** provide their best
estimate of the time at which their hardware began to transmit or capture the
stream in the `start_time` field of the response.  This time stamp **must** be
taken from the clock exposed via the
[ZX_CLOCK_MONOTONIC](../syscalls/clock_get.md) syscall.  Along with with the FIFO
depth property of the ring buffer, this timestamp allows applications to send or
receive stream data without the need for periodic position updates from the
driver.  Along with the outboard latency estimate provided by the stream
channel, this timestamp allows applications to synchronize presentation of audio
information across multiple streams, or even multiple devices (provided that an
external time synchronization protocol is used to synchronize the
[ZX_CLOCK_MONOTONIC](../syscalls/clock_get.md) timelines across the cohort of
synchronized devices).

> TODO: Redefine `start_time` to allow it to be an arbitrary 'audio stream
> clock' instead of the `ZX_CLOCK_MONOTONIC` clock.  If the stream clock is made
> to count in audio frames since start, then this `start_time` can be replaced
> with the terms for a segment of a piecewise linear transformation which can be
> subsequently updated via notifications sent by the driver in the case that the
> audio hardware clock is rooted in a different oscillator from the system's
> tick counter.  Clients can then use this transformation either to control the
> rate of consumption of input streams, or to determine where to sample in the
> input stream to effect clock correction.

Upon successfully starting a stream, drivers **must** guarantee that no position
notifications will be sent before the start response has been enqueued into the
ring-buffer channel.

Upon successfully stopping a stream, drivers **must** guarantee that no position
notifications will be enqueued into the ring-buffer channel after the stop
response has been enqueued.

### Position notifications

If requested by the application during the `GET_BUFFER` operation, the driver
will periodically send updates to the application informing it of its current
production or consumption position in the buffer.  This position is expressed in
bytes in the `ring_buffer_pos` field of the `audio_rb_position_notify_t`
message.  These messages will only ever be sent while the ring-buffer is
started.  Note, these position notifications indicate where in the buffer the
driver has consumed or produced data, *not* where the nominal playback or
capture position is.  Their arrival is not guaranteed to be perfectly uniform
and they should not be used in an attempt to effect clock recovery.  If an
application discovers that a driver has consumed past the point in the ring
buffer where it has written data for playback, the audio presentation has
certainly glitched.  Applications should increase their clock lead time and be
certain to stay ahead of this point in the stream in the future.  Likewise,
applications which are capturing audio data should make no attempt to read
beyond the point in the ring buffer indicated by the most recent position
notification sent by the driver.

Driver playback/capture positions *always* begin at byte 0 in the ring buffer
immediately following a successful start command.  When they reach the size of
the VMO (as determined by [zx_vmo_get_size(...)](../syscalls/vmo_get_size.md))
they wrap back to zero.  Drivers are not required to consume or produce data in
integral numbers of audio frames.  Client whose notion of stream position
depends on position notifications should take care to request that a sufficient
number of notifications per ring be sent (minimum 2) and that they are processed
quickly enough that aliasing does not occur.

### Error notifications

> TODO: define these and what the behavior of drivers should be in case they
> occur.

### Unexpected application termination

If the other side of a ring buffer control channel is closed for any reason,
drivers **must** immediately close the control channel, and shut down the ring
buffer such that playback ring buffers begin to produce silence.  While drivers
are encouraged to do so in a way which produces a graceful transition to
silence, the requirement is that the audio stream go silent instead of looping.
Once the transition to silence is complete, the resources associated with
playback may be released and reused by the driver.

This way, if an application teminates unexpectedly, the kernel will close the
application's channels and cause audio playback to stop instead of continuing to
loop.

### Clock recovery

> TODO: define a way that clock recovery information can be sent to clients in
> the case that the audio output oscillator is not derived from the
> `ZX_CLOCK_MONOTONIC` oscillator.  In addition, if the oscillator is slew-able in
> hardware, provide the ability to discover this capability and control the slew
> rate.  Given the fact that this oscillator is likely to be shared by multiple
> streams, it might be best to return some form of system wide clock identifier
> and provide the ability to obtain a channel on which clock recovery notifications
> can be delivered to clients and HW slewing command can be sent from clients to
> the clock.
