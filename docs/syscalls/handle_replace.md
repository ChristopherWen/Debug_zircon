# zx_handle_replace

## NAME

handle_replace - replace a handle

## SYNOPSIS

```
#include <zircon/syscalls.h>

zx_status_t zx_handle_replace(zx_handle_t handle, zx_rights_t rights, zx_handle_t* out);
```

## DESCRIPTION

**handle_replace**() creates a replacement for *handle*, referring to
the same underlying object, with new access rights *rights*. On success,
*handle* is invalidated.

If *rights* is **ZX_RIGHT_SAME_RIGHTS**, the replacement handle will
have the same rights as the original handle. Otherwise, *rights* must be
a subset of original handle's rights.

## RETURN VALUE

**handle_replace**() returns ZX_OK and the replacement handle (via *out)
on success.

## ERRORS

**ZX_ERR_BAD_HANDLE**  *handle* isn't a valid handle.

**ZX_ERR_INVALID_ARGS**  The *rights* requested are not a subset of
*handle*'s rights or *out* is an invalid pointer.

**ZX_ERR_NO_MEMORY**  (Temporary) out of memory situation.

## SEE ALSO

[handle_close](handle_close.md),
[handle_duplicate](handle_duplicate.md).
