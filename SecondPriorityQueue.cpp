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
    heap[size] = newElement;
    int currentLocation = size;
    size++;
    while (currentLocation != 0)
    {
        int parent = (currentLocation - 1) / 2;
        if (relation(heap[parent].second, p))
        {
            return;
        }
        swap(heap[parent], heap[currentLocation]);
        currentLocation = parent;
    }
    if (!relation(firstElement.second, p))
    {
        swap(firstElement, heap[0]);
    }
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
    Element elementToBePopped = heap[0];
    swap(heap[0], heap[size - 1]);
    --size;

    if (size > 0) {
        // trying to bubble down the root only if there are any nodes left in the heap
        bool isHeap = false;
        int currentNode = 0;
        int sonToTravelTo, leftSon, rightSon;
        while (isHeap == false) {
            isHeap = true;
            leftSon = rightSon = -1;
            if (currentNode * 2 + 1 < size)
                leftSon = currentNode * 2 + 1;
            if (currentNode * 2 + 2 < size)
                rightSon = currentNode * 2 + 2;
            sonToTravelTo = leftSon;
            if (sonToTravelTo != -1) { // if the left son is -1 then surely the right son doesn't exist either (currentNode is a leaf)
                if (rightSon != -1 && relation(heap[rightSon].second, heap[leftSon].second))
                    sonToTravelTo = rightSon;
            }
            if (sonToTravelTo != -1 && !relation(heap[currentNode].second, heap[sonToTravelTo].second)) {
                isHeap = false;
                swap(heap[currentNode], heap[sonToTravelTo]);
                currentNode = sonToTravelTo;
            }
        }
    }

    return elementToBePopped;
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
