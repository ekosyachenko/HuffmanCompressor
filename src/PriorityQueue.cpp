#include "PriorityQueue.h"
#include "HuffTreeNode.h"


PriorityQueue::PriorityQueue()
{

}

PriorityQueue::~PriorityQueue()
{

}

void PriorityQueue::Push(HuffTreeNode * node)
{
    if (heap.size() == 0)
    {
        heap.push_back(nullptr);
    }

    heap.push_back(node);
    count++;
    int position = count;
    while ((position / 2 > 0) && (*heap[position / 2] > *node))
    {
        swap(heap[position], heap[position / 2]);
        position = position / 2;
    }
}

HuffTreeNode* PriorityQueue::Peek() throw (exception)
{
    if (count == 0)
    {
        throw logic_error("Trying to peek from empty queue");
    }
    return heap[1];
}

HuffTreeNode* PriorityQueue::Pop() throw (exception)
{
    if (count == 0)
    {
        throw logic_error("Trying to pop from empty queue");
    }

    HuffTreeNode* node = heap[1];
    heap[1] = heap[count];
    heap.pop_back();
    count--;
    percolateDown(1);
    return node;
}

bool PriorityQueue::isEmpty()
{
    return count == 0;
}

int PriorityQueue::getSize()
{
    return count;
}

void PriorityQueue::percolateDown(int position)
{
    int child = 2 * position;
    if (child > count)
    {
        return;
    }
    if ((count != child) && (*heap[child] > *heap[child + 1]))
    {
        child++;
    }
    if (*heap[position] > *heap[child])
    {
        swap(heap[position], heap[child]);
        percolateDown(child);
    }
}
