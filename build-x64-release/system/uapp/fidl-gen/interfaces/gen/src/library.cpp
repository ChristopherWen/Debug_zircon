#include <lib/fidl/internal.h>

extern "C" {

extern const fidl_type_t test_TestTable;


static const ::fidl::FidlField test_TestFields[] = {};
const fidl_type_t test_TestTable = fidl_type_t(::fidl::FidlCodedStruct(test_TestFields, 0, 8, "test/Test"));

} // extern "C"
