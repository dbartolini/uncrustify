/**
 * @file windows_compat.h
 * Hacks to work with different versions of windows.
 * This is only included if WIN32 is set.
 *
 * @author  Ben Gardner
 * @license GPL v2+
 */
#ifndef WINDOWS_COMPAT_H_INCLUDED
#define WINDOWS_COMPAT_H_INCLUDED

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifdef WIN32
#include "windows.h"
#endif

#define HAVE_SYS_STAT_H

#define NO_MACRO_VARARG

typedef char                 CHAR;

typedef signed char          INT8;
typedef short                INT16;
typedef int                  INT32;

typedef unsigned char        UINT8;
typedef unsigned short       UINT16;
typedef unsigned int         UINT32;
typedef unsigned long long   UINT64;

#ifndef PRIx64
#define PRIx64    "llx"
#endif

#ifndef PRIu64
#define PRIu64    "llu"
#endif

// Make sure to keep GNU style attributes if they are supported; other
// included headers may have chosen to rely on them. This is essential
// if building with libc++ headers, where attributes are relied upon
// if they are supported (see _LIBCPP_EXCLUDE_FROM_EXPLICIT_INSTANTIATION).
#ifndef __GNUC__
// eliminate GNU's attribute
#define __attribute__(x)
#endif

/*
 * MSVC compilers before VC7 don't have __func__ at all; later ones call it
 * __FUNCTION__.
 */
#ifdef _MSC_VER
#if _MSC_VER < 1300
#define __func__    "???"
#else
#define __func__    __FUNCTION__
#endif
#else // _MSC_VER
#ifndef __GNUC__
#define __func__    "???"
#endif // __GNUC__
#endif // _MSC_VER

#include "stdio.h"
#include "string.h"

#undef snprintf
#define snprintf       _snprintf

#undef vsnprintf
#define vsnprintf      _vsnprintf

#undef strcasecmp
#define strcasecmp     _strcmpi

#undef strncasecmp
#define strncasecmp    _strnicmp

#undef strdup
#define strdup         _strdup

#undef fileno
#define fileno         _fileno

// includes for _setmode()
#ifdef WIN32
#include <direct.h>
#include <io.h>
#endif
#include <fcntl.h>

// on windows the file permissions have no meaning thus neglect them
#define mkdir(x, y)    _mkdir(x)

#define PATH_SEP    '\\'

#endif /* WINDOWS_COMPAT_H_INCLUDED */
