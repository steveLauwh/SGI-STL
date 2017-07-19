/*
 * Copyright (c) 1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */ 

#ifndef __SGI_STL_STRING_FWD_H
#define __SGI_STL_STRING_FWD_H

#include <stddef.h>
#include <stl_config.h>
#include <stl_alloc.h>
#include <char_traits.h>

__STL_BEGIN_NAMESPACE

template <class _CharT, 
          class _Traits = char_traits<_CharT>, 
          class _Alloc = __STL_DEFAULT_ALLOCATOR(_CharT) >
class basic_string;

typedef basic_string<char>    string;
typedef basic_string<wchar_t> wstring;

static const char* __get_c_string(const string&);

__STL_END_NAMESPACE

#endif /* __SGI_STL_STRING_FWD_H */

// Local Variables:
// mode:C++
// End:
