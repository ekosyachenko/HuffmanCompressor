#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include "HuffTreeNode.h"
#include "SupportFunctions.h"
#include "BitWriter.h"
using namespace std;

int main(int argc, char const *argv[])
{
    string fileName;

    if (argc > 1)
    {
        fileName = argv[1];
    }
    else
    {
        cout << "No file name provided." << endl;
        return 1;
    }

    unsigned short symbolFrequency[256] = {0};

    int totalCount = FillFrequencyTable(fileName, symbolFrequency);

    PriorityQueue pQueue;

    InitPriorityQueue(pQueue, symbolFrequency);

    int encoding[256][2] = {0}; //array to store bits and numBits for every character

    if (! pQueue.isEmpty())
    {
        HuffTreeNode *finalTree = ReducePriorityQueue(pQueue);
        FillEncodingTable(encoding, finalTree);
        delete finalTree;
    }

    ofstream outFile;
    outFile.open(fileName+".huf", ios::binary);

    for (int i = 0; i<256; i++)
    {
        WriteAsUChar(symbolFrequency[i], &outFile);
    }
    WriteAsUChar(totalCount, &outFile);


    ifstream inFile;
    inFile.open(fileName, ios::binary);

    unsigned char symbol;

    BitWriter bitWriter = BitWriter(&outFile); //

    while (inFile >> noskipws >> symbol)
    {
        bitWriter.WriteBits(encoding[symbol][0], encoding[symbol][1]);
    }

    bitWriter.Flush();

    inFile.close();
    outFile.close();

    return 0;
}