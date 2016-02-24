#ifndef BIT_READER_CPP
#define BIT_READER_CPP

#include <fstream>
#include <iostream>
#include "HuffTreeNode.h"
using namespace std;

class BitReader
{ 
public:
    BitReader(); 
    BitReader(ostream *outStream, istream *inStream); 
    ~BitReader(); 
    void ReadBits(HuffTreeNode* node, int totalSymbols);
private:
    istream *inStream;
    ostream *outStream; 
    unsigned char buf = 0;
};

#endif