#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using namespace std;

struct HeapNode
{
    int val;
    int key;
    HeapNode(int v,int k){val = v; key = k;};
    HeapNode(){val=-1; key=__INT_MAX__;};
};


class Heap //minHeap
{
private:
    
    int capacity;
    HeapNode **array;
public:
    int size;
    int *pos;
    Heap(int c);
    ~Heap();
    void swapNodes(HeapNode **a,HeapNode **b);
    void heapify(int i);
    bool isEmpty();
    HeapNode* extractMin();
    void decreaseKey(int v, int k);
    bool isThere(int v);
    void insert(int v, int k);
    void display();
};

#include "Heap.cpp"
#endif