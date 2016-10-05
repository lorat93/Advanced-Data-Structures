#include "BitInputStream.hpp"

/*
 * Bo Hong Carson Chan A09354706
 * Lora Tam A09844493
 * cse 100 s2 2013
 * 8/21/13
 *
 * BitInputStream.cpp
 */
void BitInputStream::fill()
{
	buffer = input.get();
	nbits = 0;
}

int BitInputStream::readBit()
{
	//If all the bits in the buffer are read, fill the buffer first
	if(nbits == 8)
		fill();

	// Get the bit at the appropriate location in the bit buffer
	int bit = 1 & (buffer >> (7 - nbits));

	// Increment the index
	nbits++;

	return bit;
}
