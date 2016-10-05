#include "BitOutputStream.hpp"

/*
 * Bo Hong Carson Chan A09354706
 * Lora Tam A09844493
 * cse 100 s2 2013
 * 8/21/13
 * BitOutputStream.cpp
 */


void BitOutputStream::flush()
{
	output.put(buffer);
	output.flush();
	buffer = nbits = 0;
}

void BitOutputStream::writeBit(int i)
{
	//If the bit buffer is full, flush it
	if( nbits == 8 )
		flush();

	// Write the least significant bit of i into the buffer
	// at the current index.
	buffer = buffer | (i << (7 - nbits));

	// Increment the index
	nbits++;
}
