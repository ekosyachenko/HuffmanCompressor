#include "BitReader.h"

BitReader::BitReader()
{

}
    
BitReader::BitReader(ostream *outStream, istream *inStream)
{
    this-> outStream = outStream;
    this-> inStream = inStream;
}

BitReader::~BitReader()
{

}

void BitReader::ReadBits(HuffTreeNode* node, int totalSymbols)
{
    HuffTreeNode* currNode = node;

    int i = 0;
    int count = 0;
    while( i < totalSymbols)
    {
        if (count ==0)
        {
            *inStream >> buf;
            count =8;
        }
        
       if ((buf>>(count-1)) & 1)
        {
            currNode = currNode->getRight();
        }
        else
        {
            currNode = currNode->getLeft();
        }
        count--;

        if (currNode -> hasSymbol())
        {
            *outStream << currNode->getSymbol();
            currNode = node;
            i++;
        }
    }
}