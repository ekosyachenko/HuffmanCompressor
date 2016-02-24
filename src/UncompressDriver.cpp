#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include "HuffTreeNode.h"
#include "SupportFunctions.h"
#include "BitReader.h"
using namespace std;

int main(int argc, char const *argv[])
{
    string compressedFile;

    if (argc > 1)
    {
        compressedFile = argv[1];
    }
    else
    {
        cout << "No file name provided." << endl;
        return 1;
    }

    ifstream inFile;
    inFile.open(compressedFile, ios::binary);

    unsigned short symbolFrequency[256] = {0};
    for (int i = 0; i<256; i++)
    {
        symbolFrequency[i] = ReadAsUCharToShort(&inFile);
    }

    int totalCount = ReadAsUCharToInt(&inFile);

    PriorityQueue pQueue;

    ofstream outFile;
    outFile.open(compressedFile+".puf", ios::binary);

    if (totalCount > 0)
    {
        InitPriorityQueue(pQueue, symbolFrequency);
        HuffTreeNode *finalTree = ReducePriorityQueue(pQueue);

        BitReader bitReader = BitReader(&outFile, &inFile);
        bitReader.ReadBits(finalTree, totalCount);

    }

    inFile.close();
    outFile.close();

    return 0;
}