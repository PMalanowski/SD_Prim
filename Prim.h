#ifndef PRIM_H
#define PRIM_H

#include "Graph.h"
#include "PrioQueue.h"
#include "Heap.h"



void Prim_pq(Graph_list *G,bool display); // Prim's algorithm implemented on a priority queue. Display variable to tell if we want to display the MST.

void Prim_heap(Graph_list* G,bool display); // Prim's algorithm implemented on a heap. Display variable to tell if we want to display the MST.

#include "Prim.cpp"
#endif