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

#ifndef __SGI_STDEXCEPT
#define __SGI_STDEXCEPT

#include <stl_exception.h>

#if defined(__STL_USE_EXCEPTIONS) || \
    !(defined(_MIPS_SIM) && defined(_ABIO32) && _MIPS_SIM == _ABIO32)

#include <stl_string_fwd.h>

__STL_BEGIN_NAMESPACE

class __Named_exception : public __STL_EXCEPTION_BASE {
public:
  __Named_exception(const string& __str) {
    strncpy(_M_name, __get_c_string(__str), _S_bufsize);
    _M_name[_S_bufsize - 1] = '\0';
  }
  virtual const char* what() const __STL_NOTHROW { return _M_name; }

private:
  enum { _S_bufsize = 256 };
  char _M_name[_S_bufsize];
};

class logic_error : public __Named_exception {
public:
  logic_error(const string& __s) : __Named_exception(__s) {}
};

class runtime_error : public __Named_exception {
public:
  runtime_error(const string& __s) : __Named_exception(__s) {}
};

class domain_error : public logic_error {
public:
  domain_error(const string& __arg) : logic_error(__arg) {}
};

class invalid_argument : public logic_error {
public:
  invalid_argument(const string& __arg) : logic_error(__arg) {}
};

class length_error : public logic_error {
public:
  length_error(const string& __arg) : logic_error(__arg) {}
};

class out_of_range : public logic_error {
public:
  out_of_range(const string& __arg) : logic_error(__arg) {}
};

class range_error : public runtime_error {
public:
  range_error(const string& __arg) : runtime_error(__arg) {}
};

class overflow_error : public runtime_error {
public:
  overflow_error(const string& __arg) : runtime_error(__arg) {}
};

class underflow_error : public runtime_error {
public:
  underflow_error(const string& __arg) : runtime_error(__arg) {}
};

__STL_END_NAMESPACE

#ifndef __SGI_STL_STRING
#include <string>
#endif

#endif /* Not o32, and no exceptions */

#endif /* __SGI_STDEXCEPT */

// Local Variables:
// mode:C++
// End:
