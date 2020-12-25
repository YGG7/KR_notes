//
// Created by Aurora on 2020/12/19.
//
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#else
    #define HDR "default.h"
#endif

#include HDR