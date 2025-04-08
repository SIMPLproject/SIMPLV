#if !defined(__SIMPLV_H__)
# warning "Please include simpl.h instead of directly including builtin_wrapper.h"
#endif

#ifndef __BUILTIN_WRAPPER_H__
#define __BUILTIN_WRAPPER_H__

#define _MM_HINT_ET0 7 /* L1 */
#define _MM_HINT_ET1 6 /* L2 */
#define _MM_HINT_T0  3 /* L1 */
#define _MM_HINT_T1  2 /* L2 */
#define _MM_HINT_T2  1 /* L3 */
#define _MM_HINT_NTA 0 /* Non-temporal access */

/*
 * __builtin_prefetch() is a GCC built-in function that hints to the compiler
 * that a certain memory location will be accessed in the future.
 * The function takes three arguments:
 * 1. The address of the memory location to prefetch.
 * 2. A boolean value indicating whether the data is read (1) or written (0).
 * 3. The cache level to prefetch to (0 for L1, 1 for L2, 2 for L3).
 */

#define sprefetch(a, cache_level) (__builtin_prefetch((const void *)(a), \
                                         ((cache_level) >> 2) & 1, (cache_level) & 0x3)) 

#endif /* __BUILTIN_WRAPPER_H__ */
