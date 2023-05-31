#include "Heap.h"


Heap::Heap(int c)
{
    this->capacity = c;
    this->size = 0;
    array = new HeapNode*[c];
    for(int i=0; i < c; i++)
    array[i]=nullptr;
    pos = new int[c];
};

Heap::~Heap()
{
    for(int i=0; i<size;i++){
        delete[] array[i];
    }
    delete[] array;
    //cout << "Heap destructed." << endl;
};

void Heap::swapNodes(HeapNode **a,HeapNode **b){
    HeapNode *temp = *a;
    *a = *b;
    *b = temp;
};

void Heap::heapify(int i){
    int smallest, left, right;
    smallest = i;
    left = 2*i+1;
    right = 2*i+2;

    if(left < this->size && array[left]->key < array[smallest]->key) smallest = left;
    if(right < this->size && array[right]->key < array[smallest]->key) smallest = right;
    if(smallest != i){
        HeapNode *smallestNode = array[smallest];
        HeapNode *iNode = array[i];
        pos[smallestNode->val] = i;
        pos[iNode->val] = smallest;

        swapNodes(&array[smallest],&array[i]);
        heapify(smallest);
    }
};

bool Heap::isEmpty(){
    return this->size==0;
};

HeapNode* Heap::extractMin(){
    if(this->isEmpty()){
        return nullptr;
    }
    this->display();
    HeapNode *root = array[0];
    HeapNode *lastNode = array[this->size-1];
    array[0] = lastNode;
    pos[root->val] = this->size - 1;
    pos[lastNode->val] = 0;

    this->size--;
    heapify(0);

    return root;
};

void Heap::decreaseKey(int v, int k){
    int i = pos[v];
    this->array[i]->key = k;
    while (i != 0 && array[i]->key < array[(i-1)/2]->key)
    {
        pos[array[i]->val] = (i-1)/2;
        pos[array[(i-1)/2]->val] = i;
        swapNodes(&array[i],&array[(i-1)/2]);
        i = (i-1)/2;
    }
};

bool Heap::isThere(int v){
    if(pos[v]<=this->size)
        return true;
    return false;
};

void Heap::insert(int v, int k){
    if(size == capacity){
        cout << "Heap is full!" << endl;
        return;
    }
    size++;
    int i = size - 1;
    array[i] = new HeapNode(v,k);
    while (i != 0 && array[i]->key < array[(i-1)/2]->key)
    {
        pos[array[i]->val] = (i-1)/2;
        pos[array[(i-1)/2]->val] = i;
        
        swapNodes(&array[i],&array[(i-1)/2]);
        i = (i-1)/2;
    }
    
};

void Heap::display(){
    for(int i=0;i < this->size+1;i++){
        cout << i << ":" << array[i]->val << ", " << array[i]->key << endl;
    }
};