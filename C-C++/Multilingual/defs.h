#ifndef __DEFS_H
#define __DEFS_H

#include <stdio.h>

#define T "true"
#define F "false"

#ifdef __cplusplus
#include <iostream>
#undef T
#undef F

#define T "waar"
#define F "onwaar"
#endif

#endif