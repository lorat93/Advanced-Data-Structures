#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP
#include <iostream>
/*
 * Bo Hong Carson Chan A09354706
 * Lora Tam A09844493
 * cse 100 s2 2013
 * 8/21/13
 * 
 * BitInputStream.hpp
 *
 *  A class that allows reading individual bits from an 
 *  input stream.
 *  To fill the buffer from the input call BitInputStream::fill()
 *  To read the next bit from the buffer call BitInputStream::readBit()
 *
 */
class BitInputStream
{
  private:
    // One byte buffer of bits
    char buffer;

    // Number of bits read from buf
    int nbits;

    // The input stream to use
    std::istream & input;

  public:

   /** Initialize a BitInputStream that will use
    *  the given istream for input.
    */
   BitInputStream(std::istream &is):input(is)
  {
    buffer = 0;
    nbits = 8;
  }

   /** Fill the buffer from the input */
   void fill();

   int readBit();

};

#endif // BITINPUTSTREAM_HPP
