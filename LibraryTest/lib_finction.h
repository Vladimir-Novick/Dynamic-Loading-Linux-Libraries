#pragma once

#ifndef lib_finction_h__
#define lib_finction_h__

#include <stdio.h>

extern "C" {
	extern void lib_finction(char* inputValue, unsigned char* src, unsigned char* dest, int len);
}


#endif