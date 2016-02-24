#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>
#include <stdexcept>
#include <iostream>
#include "HuffTreeNode.h"
using namespace std;

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    void Push(HuffTreeNode * node);
    HuffTreeNode* Peek() throw (exception);
    HuffTreeNode* Pop() throw (exception);

    bool isEmpty();
    int getSize();

private:
    vector<HuffTreeNode*> heap;
    int count = 0;
    void percolateDown(int index);

};

#endif