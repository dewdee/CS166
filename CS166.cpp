// CS166.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "RC4.h"

int main()
{
	//key[] contains 7 bytes of key
	unsigned char key[7] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x77}; 

	RC4 test(key, 7);
	test.prga();

    return 0;
}

