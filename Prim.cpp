#include "Prim.h"

void Prim_pq(Graph_list *G,bool display){
    int size = G->N;
    PrioQueue pq;
    int src = 0;
    int sum = 0;
    int key[size];
    int parent[size];
    bool inMST[size];
    for(int i = 0; i < size; i++){
        key[i] = __INT_MAX__;
        parent[i] = -1;
        inMST[i] = false;
    }
    pq.enqueue(src,0);
    key[src] = 0;
    
    while (!pq.isEmpty())
    {
        adjNode* front = pq.dequeue();
        int u = front->val;

        if(inMST[u]){
            continue;
        }
        inMST[u] = true;


        adjNode* temp = G->adjList[u];
        while (temp != nullptr)
        {
            
            int v = temp->val;
            int weight = temp->cost;
            if(inMST[v] == false && key[v] > weight){
                key[v] = weight;
                pq.enqueue(v,key[v]);
                parent[v] = u;
            }
            temp = temp->next;
        }
        
    }
    
    if(display){
        cout << "-----MST using PQ-----" << endl;
        for(int i = 1; i < size; i++){
            cout << parent[i] << "->" << i  << " (" << key[i] << ")" << endl;
            sum += key[i];
        }
        cout << "----------------------" << endl;
        cout << "Final cost of MST: " << sum << endl;
        cout << "----------------------" << endl;
    }
};

void Prim_heap(Graph_list* G,bool display){
    int V = G->N;
    int parent[V];
    int key[V];
    int sum = 0;
    Heap H(V);
    for(int i = 1; i < V; i++){
        parent[i] = -1;
        key[i] = __INT_MAX__;
        H.insert(i,key[i]);
        H.pos[i] = i;
    }

    key[0] = 0;
    H.insert(0,key[0]);
    H.pos[0] = 0;

    while (!H.isEmpty())
    {
        
        HeapNode *minNode = H.extractMin();
        int u = minNode->val;
        cout << "u=" << u <<" w=" << minNode->key <<endl;
        adjNode *temp = G->adjList[u];
        while (temp != nullptr)
        {
            int v = temp->val;
            int weight = temp->cost;
            
            cout << "v=" << v << "w=" << weight <<"pos=" << H.pos[v] << endl;
            if(H.isThere(v) && key[v] > weight){
                cout << "ide dalej" << endl;
                key[v] = weight;
                parent[v] = u;
                H.decreaseKey(v,key[v]);
            }
            temp = temp->next;
        }
    }
    
    if(display){
        cout << "----MST using heap----" << endl;
        for(int i = 1; i < V; i++){
            cout << parent[i] << "->" << i << " (" << key[i] << ")" << endl;
            sum += key[i];
        }
        cout << "----------------------" << endl;
        cout << "Final cost of MST: " << sum << endl;
        cout << "----------------------" << endl;
    }
};