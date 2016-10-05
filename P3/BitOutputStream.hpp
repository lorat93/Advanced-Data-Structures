#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP
#include <iostream>

/*
 * Bo Hong Carson Chan A09354706
 * Lora Tam A09844493
 * cse 100 s2 2013
 * 8/21/13
 *  
 * BitOutputStream.hpp
 *
 *  A class that allows writing individual bits to an
 *  output stream.
 *  To send the buffer to output and clear it  call BitOutputStream::flush()
 *  To write the next bit to the buffer call BitOutputStream::writeBit()
 *
 */
class BitOutputStream
{
  private:
    // One byte buffer of bits
    char buffer;

    // Number of bits written to buf
    int nbits;

  public:

   // The output stream to use
   std::ostream & output;

   /** Initialize a BitOutputStream that will use
    *  the given ostream for output.
    */
   BitOutputStream(std::ostream & os):output(os)
  {
    	buffer = 0;
	nbits = 0;
  }

   /** Send the buffer to output and clear it */
   void flush();

   /** Write the least significant bit of the argument to
    *  the bit buffer, and increment the bit buffer index.
    *  But flush the buffer first if it is full.
    */
   void writeBit(int i);

};
#endif // BITOUTPUTSTREAM_HPP
