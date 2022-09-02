//
// Created by admin on 2022/9/2.
//

//用于定义一些宏
#pragma once

#ifdef __GNUC__
   #define __MATX_INLINE__ __attribute__((always_inline)) inline
#elif __CUDACC__
   #define __MATX_INLINE__ __forceinline__
#else
   #define __MATX_INLINE__ inline
#endif