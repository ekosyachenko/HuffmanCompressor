#ifndef SUPPORT_FUNCTIONS_H
#define SUPPORT_FUNCTIONS_H

#include <fstream>
#include <math.h>

int FillFrequencyTable(string fileName, unsigned short frequencies[])
{
    int totalSymbols = 0;
    ifstream ifs;
    ifs.open(fileName, ios::binary);

    unsigned char symbol;

    while (ifs >> noskipws >> symbol)
    {
        frequencies[symbol]++;
        totalSymbols++;
    }

    ifs.close();
    return totalSymbols;

}   

void InitPriorityQueue(PriorityQueue &pQueue, unsigned short symbolFrequency[])
{
    for (int i = 0; i <= 255; i++)
    {
        if (symbolFrequency[i] != 0)
        {
            HuffTreeNode *node = new HuffTreeNode(i, symbolFrequency[i]);
            pQueue.Push(node);
        }
    }
}

HuffTreeNode* ReducePriorityQueue(PriorityQueue &pQueue)
{
    while (pQueue.getSize() > 1)
    {
        HuffTreeNode *node1 = pQueue.Pop();

        HuffTreeNode *node2 = pQueue.Pop();

        HuffTreeNode *node3 = *node1 + *node2; //node1 and node2 become leaves of node3

        pQueue.Push(node3);

    }

    HuffTreeNode *finalTree = pQueue.Pop();
    return finalTree;
}

void encGenerator(int (&encoding)[256][2], HuffTreeNode* hTree, int curBits, int curNumBits)
{
    if (hTree == nullptr)
    {
        return;
    }
    encGenerator(encoding, hTree -> getLeft(), curBits<<1, curNumBits+1);
    if (hTree -> hasSymbol())
    {
        encoding[hTree -> getSymbol()][0] = curBits;
        encoding[hTree -> getSymbol()][1] = curNumBits;
        
    }
    encGenerator(encoding, hTree -> getRight(), (curBits<<1) +1, curNumBits+1);
}

void FillEncodingTable(int (&encoding)[256][2], HuffTreeNode* hTree)
{
    encGenerator(encoding, hTree, 0, 0);
}

void WriteAsUChar(unsigned short value, ostream *outStream)
{
    unsigned char firstHalf = 0;
    unsigned char secondHalf = 0;

    firstHalf = (unsigned char)(value >> 8); // to copy the first 8 bits.
    secondHalf = (unsigned char)(value);
    *outStream << firstHalf << secondHalf;
}

void WriteAsUChar(int value, ostream *outStream)
{
    unsigned char partInt = 0;

    for (int i = 0; i<4; i++)
    {
        partInt = (unsigned char)(value >> (8*(3-i)));
        *outStream << partInt;
    }
}

unsigned short ReadAsUCharToShort(istream *inStream)
{
    unsigned char chSymbol = 0;
    unsigned short shSymbol = 0;

    *inStream >> noskipws >> chSymbol;
    shSymbol = shSymbol | chSymbol ;
    shSymbol = shSymbol << 8;

    *inStream >> noskipws >> chSymbol;
    shSymbol = shSymbol | chSymbol;
    return shSymbol;
}

int ReadAsUCharToInt(istream *inStream)
{
    unsigned char chSymbol = 0;
    int intSymbol = 0;

    for (int i = 0; i<4; i++)
    {
        intSymbol = (intSymbol << 8);
        *inStream >> noskipws >> chSymbol;
        intSymbol += chSymbol;
    }

    return intSymbol;
}

#endif

