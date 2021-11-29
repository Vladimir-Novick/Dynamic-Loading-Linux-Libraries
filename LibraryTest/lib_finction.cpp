#include "lib_finction.h"

#include <stdio.h>
#include <string.h>

void lib_finction(char* inputValue,unsigned char* src, unsigned char* dest, int len)
{
	puts(inputValue);
	memcpy(dest, src, len);
}
