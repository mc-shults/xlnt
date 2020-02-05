#pragma once

#ifdef _MSC_VER

#if defined(_IA64_) || defined(_AMD64_)
#define __XLNT_PLATFORM "x64"
#else
#define __XLNT_PLATFORM "x86"
#endif

#ifdef _DEBUG
#define __XLNT_DEBUG "Debug"
#define __XLNT_DEBUG_SHORT "d"
#else
#define __XLNT_DEBUG "Release"
#define __XLNT_DEBUG_SHORT ""
#endif

#define __XLNT_LIB_NAME __XLNT_PLATFORM "-" __XLNT_DEBUG "\\source\\xlnt" __XLNT_DEBUG_SHORT ".lib"

#if defined(_XLNT_AUTO_LINK)
#pragma comment(lib, __XLNT_LIB_NAME)
#pragma message("Automatically linking with " __XLNT_LIB_NAME)
#endif

#endif
