#ifndef BIT_WRITER_CPP
#define BIT_WRITER_CPP

#include <fstream>
#include <math.h>
using namespace std;

class BitWriter 
{ 
public:
    BitWriter(); 
    BitWriter(ostream *outStream); 
    ~BitWriter();
    void setStream(ostream *outStream); 
    void WriteBits(unsigned bits, int numBits); 
    int Flush();
private:
    ostream *outStream; 
    int count = 0; 
    unsigned char buf = 0;
};

#endif


