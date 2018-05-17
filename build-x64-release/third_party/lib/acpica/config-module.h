#pragma once
#define MODULE_COMPILEFLAGS "-Ithird_party/lib/acpica/source/include/acpica"
#define MODULE_CFLAGS "-Wno-discarded-qualifiers_-Wno-format-signedness_-Wno-implicit-fallthrough_-fno-strict-aliasing"
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-kernel.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "third_party/lib/acpica/source/components/hardware/hwregs.c_third_party/lib/acpica/source/components/hardware/hwsleep.c_third_party/lib/acpica/source/components/hardware/hwvalid.c_third_party/lib/acpica/source/components/hardware/hwxface.c_third_party/lib/acpica/source/components/hardware/hwxfsleep.c_third_party/lib/acpica/source/components/tables/tbdata.c_third_party/lib/acpica/source/components/tables/tbfadt.c_third_party/lib/acpica/source/components/tables/tbfind.c_third_party/lib/acpica/source/components/tables/tbinstal.c_third_party/lib/acpica/source/components/tables/tbprint.c_third_party/lib/acpica/source/components/tables/tbutils.c_third_party/lib/acpica/source/components/tables/tbxface.c_third_party/lib/acpica/source/components/tables/tbxfroot.c_third_party/lib/acpica/source/components/utilities/utalloc.c_third_party/lib/acpica/source/components/utilities/utexcep.c_third_party/lib/acpica/source/components/utilities/utglobal.c_third_party/lib/acpica/source/components/utilities/utmisc.c_third_party/lib/acpica/source/components/utilities/utstring.c_third_party/lib/acpica/source/components/utilities/utxferror.c_third_party/lib/acpica/source/os_specific/service_layers/oszircon.cpp"
#define MODULE_HEADER_DEPS ""
#define MODULE_TYPE ""

