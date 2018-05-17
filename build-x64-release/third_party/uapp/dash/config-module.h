#pragma once
#define DEBUG 1
#define MODULE_LIBS "system/ulib/zircon_system/ulib/launchpad_system/ulib/c_system/ulib/fdio__"
#define MODULE_STATIC_LIBS "system/ulib/pretty_third_party/ulib/linenoise"
#define MODULE_COMPILEFLAGS "-I./build-x64-release/system/ulib/c/gen/include_-I./build-x64-release/system/ulib/fdio/gen/include_-I./build-x64-release/system/ulib/launchpad/gen/include_-I./build-x64-release/system/ulib/pretty/gen/include_-I./build-x64-release/system/ulib/zircon/gen/include_-I./build-x64-release/third_party/ulib/linenoise/gen/include_-Iglobal/include_-Isystem/ulib/c/include_-Isystem/ulib/fdio/include_-Isystem/ulib/launchpad/include_-Isystem/ulib/pretty/include_-Isystem/ulib/zircon/include_-Ithird_party/uapp/dash/include_-Ithird_party/ulib/linenoise/include_-Ithird_party/ulib/musl/include"
#define MODULE_CFLAGS "-DBSD_-DIFS_BROKEN_-DJOBS=0_-DSHELL_-DUSE_LINENOISE_-D_GNU_SOURCE_-Ithird_party/uapp/dash/src_-Wno-discarded-qualifiers_-Wno-error_-Wno-logical-not-parentheses_-Wno-sign-compare_-Wno-strict-prototypes_-include_third_party/uapp/dash/config.h"
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-user.h_./build-x64-release/system/ulib/c/gen-hdr.stamp_./build-x64-release/system/ulib/fdio/gen-hdr.stamp_./build-x64-release/system/ulib/launchpad/gen-hdr.stamp_./build-x64-release/system/ulib/pretty/gen-hdr.stamp_./build-x64-release/system/ulib/zircon/gen-hdr.stamp_./build-x64-release/third_party/ulib/linenoise/gen-hdr.stamp"
#define MODULE_DEPS ""
#define MODULE_SRCS "third_party/uapp/dash/src/alias.c_third_party/uapp/dash/src/arith_yacc.c_third_party/uapp/dash/src/arith_yylex.c_third_party/uapp/dash/src/bltin/printf.c_third_party/uapp/dash/src/bltin/test.c_third_party/uapp/dash/src/bltin/times.c_third_party/uapp/dash/src/bltin/zircon.c_third_party/uapp/dash/src/builtins.c_third_party/uapp/dash/src/cd.c_third_party/uapp/dash/src/error.c_third_party/uapp/dash/src/eval.c_third_party/uapp/dash/src/exec.c_third_party/uapp/dash/src/expand.c_third_party/uapp/dash/src/init.c_third_party/uapp/dash/src/input.c_third_party/uapp/dash/src/jobs.c_third_party/uapp/dash/src/main.c_third_party/uapp/dash/src/memalloc.c_third_party/uapp/dash/src/miscbltin.c_third_party/uapp/dash/src/mystring.c_third_party/uapp/dash/src/nodes.c_third_party/uapp/dash/src/options.c_third_party/uapp/dash/src/output.c_third_party/uapp/dash/src/output.h_third_party/uapp/dash/src/parser.c_third_party/uapp/dash/src/process.c_third_party/uapp/dash/src/redir.c_third_party/uapp/dash/src/show.c_third_party/uapp/dash/src/signames.c_third_party/uapp/dash/src/syntax.c_third_party/uapp/dash/src/system.c_third_party/uapp/dash/src/tab.c_third_party/uapp/dash/src/trap.c_third_party/uapp/dash/src/var.c"
#define MODULE_HEADER_DEPS "system/ulib/c_system/ulib/fdio_system/ulib/launchpad_system/ulib/pretty_system/ulib/zircon_third_party/ulib/linenoise"
#define MODULE_TYPE "userapp"

