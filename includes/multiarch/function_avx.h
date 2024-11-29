#ifndef __WARNING_FUNCTION_AVX_H__
# warning "Please include simpl.h instead of directly including function_avx.h"
#endif

#ifndef __FUNCTION_AVX_H__
# define __FUNCTION_AVX_H__

# define __SIMPLV_TYPE_ONLY
# include "../simpl.h"
# undef __SIMPLV_TYPE_ONLY

# ifndef __FUNC_ATTR_AVX
#  define __FUNC_ATTR_AVX                                                                          \
	  __attribute__((__always_inline__, __nodebug__, __target__("avx"), __min_vector_width__(256)))
# endif

# ifndef _FUNC_AVX
#  define _FUNC_AVX(x) __simpl_##x##_avx
# endif

# define __BASIC_FUNC_AVX_256(name, type, sign)                                                    \
	 static inline vec __FUNC_ATTR_AVX _FUNC_AVX(name)(vec __a, vec __b)                           \
	 {                                                                                             \
		 vec                                   result;                                             \
		 result.type.v256 = __a.type.v256 sign __b.type.v256;                                      \
		 return result;                                                                            \
	 }

# define __BASIC_FUNC_AVX_256_ALL_TYPE(name, sign)                                                 \
	 __BASIC_FUNC_AVX_256(v32c_##name, t_char, sign)                                               \
	 __BASIC_FUNC_AVX_256(v32sc_##name, t_schar, sign)                                             \
	 __BASIC_FUNC_AVX_256(v32uc_##name, t_uchar, sign)                                             \
	 __BASIC_FUNC_AVX_256(v16s_##name, t_short, sign)                                              \
	 __BASIC_FUNC_AVX_256(v16us_##name, t_ushort, sign)                                            \
	 __BASIC_FUNC_AVX_256(v8i_##name, t_int, sign)                                                 \
	 __BASIC_FUNC_AVX_256(v8ui_##name, t_uint, sign)                                               \
	 __BASIC_FUNC_AVX_256(v8f_##name, t_float, sign)                                               \
	 __BASIC_FUNC_AVX_256(v4d_##name, t_double, sign)                                              \
	 __BASIC_FUNC_AVX_256(v4ll_##name, t_long_long, sign)                                          \
	 __BASIC_FUNC_AVX_256(v4ull_##name, t_ulong_long, sign)

# define __BASIC_FUNC_AVX_ALL_TYPE(name, sign) __BASIC_FUNC_AVX_256_ALL_TYPE(name, sign)

__BASIC_FUNC_AVX_ALL_TYPE(add, +)
__BASIC_FUNC_AVX_ALL_TYPE(sub, -)
__BASIC_FUNC_AVX_ALL_TYPE(mul, *)
__BASIC_FUNC_AVX_ALL_TYPE(div, /)
__BASIC_FUNC_AVX_ALL_TYPE(cmpeq, ==)
__BASIC_FUNC_AVX_ALL_TYPE(cmpgt, >)
__BASIC_FUNC_AVX_ALL_TYPE(cmplt, <)
__BASIC_FUNC_AVX_ALL_TYPE(cmpge, >=)
__BASIC_FUNC_AVX_ALL_TYPE(cmple, <=)

# undef __FUNC_ATTR_AVX
# undef __SIMPLV_TYPE_ONLY

#endif /* __FUNCTION_AVX_H__ */
