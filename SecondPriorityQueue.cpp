#include <bits/exception.h>
#include "SecondPriorityQueue.h"

#define DEFAULT_CAPACITY 10

SecondPriorityQueue::SecondPriorityQueue(Relation r) : relation{r}
{
    heap = new Element[DEFAULT_CAPACITY];
    size = 0;
    capacity = DEFAULT_CAPACITY;

    firstElement = {};
    hasFirstElement = false;
}

void SecondPriorityQueue::push(TElem e, TPriority p)
{
    Element newElement = {e, p};
    if (!hasFirstElement)
    {
        firstElement = newElement;
        hasFirstElement = true;
        return;
    }
    if (size == capacity)
    {
        expandHeap();
    }
    //TODO H
}

Element SecondPriorityQueue::top() const
{
    if (size == 0)
    {
        throw std::exception();
    }
    return heap[0];
}

Element SecondPriorityQueue::pop()
{
    if (size == 0)
    {
        throw std::exception();
    }
    //TODO R
    return {};
}

bool SecondPriorityQueue::atMostOne() const
{
    return size == 0;
}

void SecondPriorityQueue::expandHeap()
{
    capacity = capacity * 2;
    Element *newHeap = new Element[capacity];
    for (int i = 0; i < size; i++)
    {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

SecondPriorityQueue::~SecondPriorityQueue()
{
    delete[] heap;
}
