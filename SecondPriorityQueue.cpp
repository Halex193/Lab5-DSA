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
    //TODO
}

Element SecondPriorityQueue::top() const
{
    if (size == 0)
    {
        throw std::exception();
    }
    //TODO
    return {};
}

Element SecondPriorityQueue::pop()
{
    if (size == 0)
    {
        throw std::exception();
    }
    //TODO
    return {};
}

bool SecondPriorityQueue::atMostOne() const
{
    return size == 0;
}

SecondPriorityQueue::~SecondPriorityQueue()
{
    delete[] heap;
}
