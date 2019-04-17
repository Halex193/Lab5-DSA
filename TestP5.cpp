#include <assert.h>
#include "SecondPriorityQueue.h"
#include "TestP5.h"
#include <vector>
#include <exception>
#include <iostream>

using namespace std;

bool rel2(TPriority p1, TPriority p2) {
    if (p1 <= p2) {
        return true;
    }
    else {
        return false;
    }
}

bool rel1(TPriority p1, TPriority p2) {
    if (p1 >= p2) {
        return true;
    }
    else {
        return false;
    }
}

void testCreate() {
    SecondPriorityQueue pq(rel2);
    assert(pq.atMostOne() == true);
    try {
        pq.top();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {
        pq.pop();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    pq.push(5, 5);
    assert(pq.atMostOne() == true);
    try {
        pq.top();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {
        pq.pop();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    std::cout << "Passed create test!\n";
    std::cout.flush();
}

void testAdd() {
    SecondPriorityQueue pq(rel2);
    for (int i = 0; i < 10; i++) {
        pq.push(i, i);
    }
    assert(pq.atMostOne() == false);
    for (int i = -10; i < 20; i++) {
        pq.push(i, i);
    }
    assert(pq.atMostOne() == false);
    for (int i = -100; i < 100; i++) {
        pq.push(i, i);
    }
    assert(pq.atMostOne() == false);

    for (int i = -1000; i <= 1000; i++) {
        pq.push(i, i);
    }
    assert(pq.atMostOne() == false);
    assert(pq.top().second != 1000);
    assert(pq.top().second == -999);

    assert(pq.pop().second == -999);
    assert(pq.top().second == -998);
    for (int i = -998; i <= -100; i++) {
        assert(pq.top().second == i);
        assert(pq.pop().second == i);
    }
    std::cout << "Passed add test!\n";
    std::cout.flush();
}

void testRemove() {
    SecondPriorityQueue pq(rel2);
    for (int i = 0; i < 10; i++) {
        pq.push(i, i);
    }
    assert(pq.top().second == 1);
    assert(pq.atMostOne() == false);
    for (int i = -10; i < 20; i++) {
        pq.push(i, i);
    }
    assert(pq.top().second == -9);
    for (int i = 100; i > 50; i--) {
        pq.push(i, i);
    }
    assert(pq.top().second == -9);

    for (int i = -10; i < 0; i++) {
        assert(pq.pop().second == i+1);
    }
    assert(pq.pop().second == 0);
    for (int i = 0; i < 9; i++) {
        assert(pq.pop().second == i+1);
        assert(pq.pop().second == i+1);
    }
    assert(pq.pop().second == 10);
    for (int i = 10; i < 18; i++) {
        assert(pq.pop().second == i+1);
    }
    assert(pq.pop().second == 19);
    for (int i = 51; i <= 100; i++) {
        //assert(pq.pop().second == i);
        pq.pop();
    }

    assert(pq.atMostOne() == true);
    std::cout << "Passed remove test!\n";
    std::cout.flush();
}

void testQuantity(Relation rel) {
    SecondPriorityQueue pq(rel);
    std::cout << "Began quantity test! " << __PRETTY_FUNCTION__ << '\n';
    std::cout << "Began quantity push!\n";
    std::cout.flush();
    for (int i = 1; i <= 10; i++) {
        for (int j = 500; j >= -500; j --) {
            pq.push(j, j);
        }
    }
    std::cout << "Ended quantity push!\n";
    int count = 1;
    Element last = pq.pop();
    std::cout << "Began quantity pop!\n";
    std::cout.flush();
    while (pq.atMostOne() == false) {
        Element current = pq.pop();
        assert(rel(last.second, current.second));
        count++;
        last = current;
    }
    std::cout << "Ended quantity pop!\n";
    std::cout.flush();
    assert(count == 10009);
    std::cout << "Passed quantity test!\n";
    std::cout.flush();
}

void testP5() {
    testCreate();
    testAdd();
    testRemove();
    testQuantity(rel2);
    testQuantity(rel1);
}