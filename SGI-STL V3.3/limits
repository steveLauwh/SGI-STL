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

/* NOTE: This is not portable code.  Parts of numeric_limits<> are
 * inherently machine-dependent.  At present this file is suitable
 * for the MIPS and ia32 architectures.
 */

#ifndef __SGI_CPP_LIMITS
#define __SGI_CPP_LIMITS

#include <limits.h>
#include <float.h>
#include <stl_config.h>

__STL_BEGIN_NAMESPACE

enum float_round_style {
  round_indeterminate       = -1,
  round_toward_zero         =  0,
  round_to_nearest          =  1,
  round_toward_infinity     =  2,
  round_toward_neg_infinity =  3
};

enum float_denorm_style {
  denorm_indeterminate = -1,
  denorm_absent        =  0,
  denorm_present       =  1
};

// The C++ standard (section 18.2.1) requires that some of the members of
// numeric_limits be static const data members that are given constant-
// initializers within the class declaration.  On compilers where the
// __STL_STATIC_CONST_INIT_BUG macro is defined, it is impossible to write
// a standard-conforming numeric_limits class.
//
// There are two possible workarounds: either initialize the data
// members outside the class, or change them from data members to
// enums.  Neither workaround is satisfactory: the former makes it
// impossible to use the data members in constant-expressions, and the
// latter means they have the wrong type and that it is impossible to
// take their addresses.  We choose the former workaround.

#ifdef __STL_STATIC_CONST_INIT_BUG
# define __STL_DECLARE_LIMITS_MEMBER(__mem_type, __mem_name, __mem_value) \
  enum { __mem_name = __mem_value }
#else /* __STL_STATIC_CONST_INIT_BUG */
# define __STL_DECLARE_LIMITS_MEMBER(__mem_type, __mem_name, __mem_value) \
  static const __mem_type __mem_name = __mem_value
#endif /* __STL_STATIC_CONST_INIT_BUG */

// Base class for all specializations of numeric_limits.

template <class __number>
class _Numeric_limits_base {
public:
  __STL_DECLARE_LIMITS_MEMBER(bool, is_specialized, false);

  static __number min() __STL_NOTHROW { return __number(); }
  static __number max() __STL_NOTHROW { return __number(); }

  __STL_DECLARE_LIMITS_MEMBER(int, digits,   0);
  __STL_DECLARE_LIMITS_MEMBER(int, digits10, 0);

  __STL_DECLARE_LIMITS_MEMBER(bool, is_signed,  false);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_integer, false);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_exact,   false);

  __STL_DECLARE_LIMITS_MEMBER(int, radix, 0);

  static __number epsilon() __STL_NOTHROW     { return __number(); }
  static __number round_error() __STL_NOTHROW { return __number(); }

  __STL_DECLARE_LIMITS_MEMBER(int, min_exponent,   0);
  __STL_DECLARE_LIMITS_MEMBER(int, min_exponent10, 0);
  __STL_DECLARE_LIMITS_MEMBER(int, max_exponent,   0);
  __STL_DECLARE_LIMITS_MEMBER(int, max_exponent10, 0);

  __STL_DECLARE_LIMITS_MEMBER(bool, has_infinity,      false);
  __STL_DECLARE_LIMITS_MEMBER(bool, has_quiet_NaN,     false);
  __STL_DECLARE_LIMITS_MEMBER(bool, has_signaling_NaN, false);
  __STL_DECLARE_LIMITS_MEMBER(float_denorm_style,
                              has_denorm,
                              denorm_absent);
  __STL_DECLARE_LIMITS_MEMBER(bool, has_denorm_loss,   false);

  static __number infinity() __STL_NOTHROW      { return __number(); }
  static __number quiet_NaN() __STL_NOTHROW     { return __number(); }
  static __number signaling_NaN() __STL_NOTHROW { return __number(); }
  static __number denorm_min() __STL_NOTHROW    { return __number(); }

  __STL_DECLARE_LIMITS_MEMBER(bool, is_iec559,  false);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_bounded, false);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_modulo,  false);

  __STL_DECLARE_LIMITS_MEMBER(bool, traps,            false);
  __STL_DECLARE_LIMITS_MEMBER(bool, tinyness_before,  false);
  __STL_DECLARE_LIMITS_MEMBER(float_round_style,
                              round_style,
                              round_toward_zero);
};

#ifdef __STL_STATIC_CONST_INIT_BUG
# define __STL_DEFINE_NUMERIC_BASE_MEMBER(__type, __mem)
#else /* __STL_STATIC_CONST_INIT_BUG */
# define __STL_DEFINE_NUMERIC_BASE_MEMBER(__type, __mem) \
  template <class __number>                              \
  const __type _Numeric_limits_base<__number>:: __mem
#endif /* __STL_STATIC_CONST_INIT_BUG */

__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, is_specialized);
__STL_DEFINE_NUMERIC_BASE_MEMBER(int, digits);
__STL_DEFINE_NUMERIC_BASE_MEMBER(int, digits10);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, is_signed);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, is_integer);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, is_exact);
__STL_DEFINE_NUMERIC_BASE_MEMBER(int, radix);
__STL_DEFINE_NUMERIC_BASE_MEMBER(int, min_exponent);
__STL_DEFINE_NUMERIC_BASE_MEMBER(int, max_exponent);
__STL_DEFINE_NUMERIC_BASE_MEMBER(int, min_exponent10);
__STL_DEFINE_NUMERIC_BASE_MEMBER(int, max_exponent10);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, has_infinity);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, has_quiet_NaN);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, has_signaling_NaN);
__STL_DEFINE_NUMERIC_BASE_MEMBER(float_denorm_style, has_denorm);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, has_denorm_loss);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, is_iec559);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, is_bounded);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, is_modulo);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, traps);
__STL_DEFINE_NUMERIC_BASE_MEMBER(bool, tinyness_before);
__STL_DEFINE_NUMERIC_BASE_MEMBER(float_round_style, round_style);


// Base class for integers.

template <class _Int,
          _Int __imin, _Int __imax,
          int __idigits = -1, bool __ismod = true>
class _Integer_limits : public _Numeric_limits_base<_Int> 
{
public:
  __STL_DECLARE_LIMITS_MEMBER(bool, is_specialized, true);

  static _Int min() __STL_NOTHROW { return __imin; }
  static _Int max() __STL_NOTHROW { return __imax; }

  __STL_DECLARE_LIMITS_MEMBER(int,
                              digits,
                              (__idigits < 0) ? (int)(sizeof(_Int) * CHAR_BIT)
                                                   - (__imin == 0 ? 0 : 1) 
                                              : __idigits);
  __STL_DECLARE_LIMITS_MEMBER(int, digits10, (digits * 301) / 1000); 
                                // log 2 = 0.301029995664...

  __STL_DECLARE_LIMITS_MEMBER(bool, is_signed,  __imin != 0);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_integer, true);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_exact,   true);
  __STL_DECLARE_LIMITS_MEMBER(int,  radix,      2);

  __STL_DECLARE_LIMITS_MEMBER(bool, is_bounded, true);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_modulo, __ismod);
};

#ifdef __STL_STATIC_CONST_INIT_BUG
# define __STL_DEFINE_INTEGER_LIMITS_MEMBER(__type, __mem)
#else /* __STL_STATIC_CONST_INIT_BUG */
# define __STL_DEFINE_INTEGER_LIMITS_MEMBER(__type, __mem)              \
  template <class _Int, _Int __imin, _Int __imax, int __idig, bool __ismod>  \
  const __type _Integer_limits<_Int, __imin, __imax, __idig, __ismod>::__mem
#endif /* __STL_STATIC_CONST_INIT_BUG */

__STL_DEFINE_INTEGER_LIMITS_MEMBER(bool, is_specialized);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(int, digits);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(int, digits10);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(bool, is_signed);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(bool, is_integer);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(bool, is_exact);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(int, radix);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(bool, is_bounded);
__STL_DEFINE_INTEGER_LIMITS_MEMBER(bool, is_modulo);


// Base class for floating-point numbers.
template <class __number,
         int __Digits, int __Digits10,
         int __MinExp, int __MaxExp,
         int __MinExp10, int __MaxExp10,
         bool __IsIEC559,
         float_round_style __RoundStyle>
class _Floating_limits : public _Numeric_limits_base<__number>
{
public:
  __STL_DECLARE_LIMITS_MEMBER(bool, is_specialized, true);

  __STL_DECLARE_LIMITS_MEMBER(int, digits,   __Digits);
  __STL_DECLARE_LIMITS_MEMBER(int, digits10, __Digits10);

  __STL_DECLARE_LIMITS_MEMBER(bool, is_signed, true);

  __STL_DECLARE_LIMITS_MEMBER(int, radix, 2);

  __STL_DECLARE_LIMITS_MEMBER(int, min_exponent,   __MinExp);
  __STL_DECLARE_LIMITS_MEMBER(int, max_exponent,   __MaxExp);
  __STL_DECLARE_LIMITS_MEMBER(int, min_exponent10, __MinExp10);
  __STL_DECLARE_LIMITS_MEMBER(int, max_exponent10, __MaxExp10);

  __STL_DECLARE_LIMITS_MEMBER(bool, has_infinity,      true);
  __STL_DECLARE_LIMITS_MEMBER(bool, has_quiet_NaN,     true);
  __STL_DECLARE_LIMITS_MEMBER(bool, has_signaling_NaN, true);
  __STL_DECLARE_LIMITS_MEMBER(float_denorm_style,
                              has_denorm,
                              denorm_indeterminate);
  __STL_DECLARE_LIMITS_MEMBER(bool, has_denorm_loss,   false);

  __STL_DECLARE_LIMITS_MEMBER(bool, is_iec559,       __IsIEC559);
  __STL_DECLARE_LIMITS_MEMBER(bool, is_bounded,      true);
  __STL_DECLARE_LIMITS_MEMBER(bool, traps,           true);
  __STL_DECLARE_LIMITS_MEMBER(bool, tinyness_before, false);

  __STL_DECLARE_LIMITS_MEMBER(float_round_style, round_style, __RoundStyle);
};

#ifdef __STL_STATIC_CONST_INIT_BUG
# define __STL_DEFINE_FLOAT_LIMITS_MEMBER(__type, __mem)
#else /* __STL_STATIC_CONST_INIT_BUG */
# define __STL_DEFINE_FLOAT_LIMITS_MEMBER(__type, __mem)                   \
  template <class __Num, int __Dig, int __Dig10,                           \
            int __MnX, int __MxX, int __MnX10, int __MxX10,                \
            bool __IsIEEE, float_round_style __Sty>                        \
  const __type _Floating_limits<__Num, __Dig, __Dig10,                     \
                                __MnX, __MxX, __MnX10, __MxX10,            \
                                __IsIEEE, __Sty>:: __mem
#endif /* __STL_STATIC_CONST_INIT_BUG */

__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, is_specialized);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(int, digits);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(int, digits10);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, is_signed);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(int, radix);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(int, min_exponent);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(int, max_exponent);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(int, min_exponent10);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(int, max_exponent10);  
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, has_infinity);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, has_quiet_NaN);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, has_signaling_NaN);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(float_denorm_style, has_denorm);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, has_denorm_loss);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, is_iec559);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, is_bounded);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, traps);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(bool, tinyness_before);
__STL_DEFINE_FLOAT_LIMITS_MEMBER(float_round_style, round_style);


#undef __STL_DECLARE_NUMERIC_LIMITS_MEMBER
#undef __STL_DEFINE_NUMERIC_BASE_MEMBER
#undef __STL_DEFINE_INTEGER_LIMITS_MEMBER
#undef __STL_DEFINE_FLOAT_LIMITS_MEMBER

// Class numeric_limits

// The unspecialized class.

template<class _Tp> 
class numeric_limits : public _Numeric_limits_base<_Tp> {};

// Specializations for all built-in integral types.

#ifndef __STL_NO_BOOL

__STL_TEMPLATE_NULL
class numeric_limits<bool>
  : public _Integer_limits<bool, false, true, 1, false>
{};

#endif /* __STL_NO_BOOL */

__STL_TEMPLATE_NULL
class numeric_limits<char>
  : public _Integer_limits<char, CHAR_MIN, CHAR_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<signed char>
  : public _Integer_limits<signed char, SCHAR_MIN, SCHAR_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<unsigned char>
  : public _Integer_limits<unsigned char, 0, UCHAR_MAX>
{};

#ifdef __STL_HAS_WCHAR_T

__STL_TEMPLATE_NULL
class numeric_limits<wchar_t>
  : public _Integer_limits<wchar_t, INT_MIN, INT_MAX>
{};

#endif

__STL_TEMPLATE_NULL
class numeric_limits<short>
  : public _Integer_limits<short, SHRT_MIN, SHRT_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<unsigned short>
  : public _Integer_limits<unsigned short, 0, USHRT_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<int>
  : public _Integer_limits<int, INT_MIN, INT_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<unsigned int>
  : public _Integer_limits<unsigned int, 0, UINT_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<long>
  : public _Integer_limits<long, LONG_MIN, LONG_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<unsigned long>
  : public _Integer_limits<unsigned long, 0, ULONG_MAX>
{};

#ifdef __STL_LONG_LONG

// Some compilers have long long, but don't define the
// LONGLONG_MIN and LONGLONG_MAX macros in limits.h.  This
// assumes that long long is 64 bits.
#if !defined(LONGLONG_MIN) && !defined(LONGLONG_MAX) \
                           && !defined(ULONGLONG_MAX)

#define ULONGLONG_MAX 0xffffffffffffffffLLU
#define LONGLONG_MAX 0x7fffffffffffffffLL
#define LONGLONG_MIN (-LONGLONG_MAX - 1LL)

#endif

__STL_TEMPLATE_NULL
class numeric_limits<long long>
  : public _Integer_limits<long long, LONGLONG_MIN, LONGLONG_MAX>
{};

__STL_TEMPLATE_NULL
class numeric_limits<unsigned long long>
  : public _Integer_limits<unsigned long long, 0, ULONGLONG_MAX>
{};

#endif /* __STL_LONG_LONG */

// Specializations for all built-in floating-point type.

__STL_TEMPLATE_NULL class numeric_limits<float>
  : public _Floating_limits<float, 
                            FLT_MANT_DIG,   // Binary digits of precision
                            FLT_DIG,        // Decimal digits of precision
                            FLT_MIN_EXP,    // Minimum exponent
                            FLT_MAX_EXP,    // Maximum exponent
                            FLT_MIN_10_EXP, // Minimum base 10 exponent
                            FLT_MAX_10_EXP, // Maximum base 10 exponent
                            true,           // conforms to iec559
                            round_to_nearest>
{
public:
  static float min() __STL_NOTHROW { return FLT_MIN; }
  static float denorm_min() __STL_NOTHROW { return FLT_MIN; }
  static float max() __STL_NOTHROW { return FLT_MAX; }
  static float epsilon() __STL_NOTHROW { return FLT_EPSILON; }
  static float round_error() __STL_NOTHROW { return 0.5f; } // Units: ulps.
  static float infinity() __STL_NOTHROW;
  static float quiet_NaN() __STL_NOTHROW;
  static float signaling_NaN() __STL_NOTHROW;
};

__STL_TEMPLATE_NULL class numeric_limits<double>
  : public _Floating_limits<double, 
                            DBL_MANT_DIG,   // Binary digits of precision
                            DBL_DIG,        // Decimal digits of precision
                            DBL_MIN_EXP,    // Minimum exponent
                            DBL_MAX_EXP,    // Maximum exponent
                            DBL_MIN_10_EXP, // Minimum base 10 exponent
                            DBL_MAX_10_EXP, // Maximum base 10 exponent
                            true,           // conforms to iec559
                            round_to_nearest>
{
public:
  static double min() __STL_NOTHROW { return DBL_MIN; }
  static double denorm_min() __STL_NOTHROW { return DBL_MIN; }
  static double max() __STL_NOTHROW { return DBL_MAX; }
  static double epsilon() __STL_NOTHROW { return DBL_EPSILON; }
  static double round_error() __STL_NOTHROW { return 0.5; } // Units: ulps.
  static double infinity() __STL_NOTHROW;
  static double quiet_NaN() __STL_NOTHROW;
  static double signaling_NaN() __STL_NOTHROW;
};

__STL_TEMPLATE_NULL class numeric_limits<long double>
  : public _Floating_limits<long double, 
                            LDBL_MANT_DIG,  // Binary digits of precision
                            LDBL_DIG,       // Decimal digits of precision
                            LDBL_MIN_EXP,   // Minimum exponent
                            LDBL_MAX_EXP,   // Maximum exponent
                            LDBL_MIN_10_EXP,// Minimum base 10 exponent
                            LDBL_MAX_10_EXP,// Maximum base 10 exponent
                            false,          // Doesn't conform to iec559
                            round_to_nearest>
{
public:
  static long double min() __STL_NOTHROW { return LDBL_MIN; }
  static long double denorm_min() __STL_NOTHROW { return LDBL_MIN; }
  static long double max() __STL_NOTHROW { return LDBL_MAX; }
  static long double epsilon() __STL_NOTHROW { return LDBL_EPSILON; }
  static long double round_error() __STL_NOTHROW { return 4; } // Units: ulps.
  static long double infinity() __STL_NOTHROW;
  static long double quiet_NaN() __STL_NOTHROW;
  static long double signaling_NaN() __STL_NOTHROW;
};

// We write special values (Inf and NaN) as bit patterns and 
// cast the the appropriate floating-point types. 

#if defined(_MIPSEB)
// Big-endian MIPS.  float is 32 bits, double 64, long double 128.

#define _Define_float(__f, __h, __l)                                     \
   inline float numeric_limits<float>::__f() __STL_NOTHROW {             \
     static const unsigned short __x[2] = { __h, __l };                  \
     return *reinterpret_cast<const float*>(__x); }
#define _Define_double(__f, __h, __l)                                    \
   inline double numeric_limits<double>::__f() __STL_NOTHROW {           \
     static const unsigned short __x[4] = { __h, __l };                  \
     return *reinterpret_cast<const double*>(__x); }
#define _Define_ldouble(__f, __h, __l)                                   \
   inline long double numeric_limits<long double>::__f() __STL_NOTHROW { \
     static const unsigned short __x[8] = { __h, __l };                  \
     return *reinterpret_cast<const long double*>(__x); }

_Define_float(infinity, 0x7f80, 0)
_Define_float(quiet_NaN, 0x7f81, 0)
_Define_float(signaling_NaN, 0x7fc1, 0)

_Define_double(infinity, 0x7ff0, 0)
_Define_double(quiet_NaN, 0x7ff1, 0)
_Define_double(signaling_NaN, 0x7ff9, 0)

_Define_ldouble(infinity, 0x7ff0, 0)
_Define_ldouble(quiet_NaN, 0x7ff1, 0)
_Define_ldouble(signaling_NaN, 0x7ff9, 0)

#elif defined(__i386) || defined(_M_IX86)
// Little-endian ia32.  float is 32 bits, double 64, long double 80.

#define _Define_float(__f, __h, __l)                                     \
   inline float numeric_limits<float>::__f() __STL_NOTHROW {             \
     static const unsigned short __x[2] = { __l, __h };                  \
     return *reinterpret_cast<const float*>(__x); }
#define _Define_double(__f, __h, __l)                                    \
   inline double numeric_limits<double>::__f() __STL_NOTHROW {           \
     static const unsigned short __x[4] = { 0, 0, __l, __h };            \
     return *reinterpret_cast<const double*>(__x); }
#define _Define_ldouble(__f, __h, __l)                                   \
   inline long double numeric_limits<long double>::__f() __STL_NOTHROW { \
     static const unsigned short __x[5] = { 0, 0, 0, __l, __h };         \
     return *reinterpret_cast<const long double*>(__x); }

_Define_float(infinity, 0x7f80, 0)
_Define_float(quiet_NaN, 0x7fa0, 0)
_Define_float(signaling_NaN, 0x7fc0, 0)

_Define_double(infinity, 0x7ff0, 0)
_Define_double(quiet_NaN, 0x7ff4, 0)
_Define_double(signaling_NaN, 0x7ff8, 0)

_Define_ldouble(infinity, 0x7fff, 0x8000)
_Define_ldouble(quiet_NaN, 0x7fff, 0xa000)
_Define_ldouble(signaling_NaN, 0x7fff, 0xc000)

#else 

/* This is an architecture we don't know how to handle.  Return some 
   obviously wrong values. */

#define _Define_float(__f)                                               \
   inline float numeric_limits<float>::__f() __STL_NOTHROW {             \
     return 0; }
#define _Define_double(__f)                                              \
   inline double numeric_limits<double>::__f() __STL_NOTHROW {           \
     return 0; }
#define _Define_ldouble(__f)                                             \
   inline long double numeric_limits<long double>::__f() __STL_NOTHROW { \
     return 0; }

_Define_float(infinity)
_Define_float(quiet_NaN)
_Define_float(signaling_NaN)

_Define_double(infinity)
_Define_double(quiet_NaN)
_Define_double(signaling_NaN)

_Define_ldouble(infinity)
_Define_ldouble(quiet_NaN)
_Define_ldouble(signaling_NaN)   

#endif

#undef _Define_float
#undef _Define_double
#undef _Define_ldouble

__STL_END_NAMESPACE

#endif /* __SGI_CPP_LIMITS */

// Local Variables:
// mode:C++
// End:
