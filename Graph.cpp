#include "Graph.h"

Graph_list::Graph_list(int nr_V){
    this->N = nr_V;
    adjList = new adjNode*[N];
    for(int i=0; i < N; i++)
    adjList[i]=nullptr;
    nr_e = 0;
    max_e = (nr_V*(nr_V-1))/2;
};

Graph_list::~Graph_list(){
    for(int i = 0; i<N; i++){
        delete adjList[i];
    }
    delete[] adjList;
    //cout << "Graph destructed." << endl;
}

void Graph_list::addEdge(int start, int end, int weight){
    adjList[start] = new adjNode(end,adjList[start],weight);
    adjList[end] = new adjNode(start,adjList[end],weight);
    this->nr_e++;
};

void Graph_list::display(){
    cout << "Displaying Graph:\nStartNode -> EndNode(Weight)" << endl;
    for(int i = 0; i < N; i++){
        if(adjList[i] != nullptr){
            cout << i << " -> ";
            for(adjNode* j = adjList[i]; j != nullptr; j = j->next){
                cout <<  j->val << "("  << j->cost << ") ";
            }
            cout << endl; 
        }
        else{
            cout << i << " has no edges" << endl;
        }
    }
};

void Graph_list::randomize(int density){
    srand(time(NULL));
    int d = max_e*density/100; // calculating the number of edges required for the graph to have desired density
    int s,e,w;
    int i = 0;
    bool existingEdge = 0;
    if(density == 100){ // if we have 100% density we connect every vertex with every other vertex (this speeds up creating graphs with 100% density)
        for (int i = 0; i < N; i++)
        {
            for(int j = i;j < N; j++){
                for(adjNode* k = adjList[i]; k != nullptr; k = k->next){ // to avoid connecting vertices that are already connected 
                    if(k->val == j){
                        existingEdge = 1;
                    }
                }
                if(i != j && !existingEdge){
                    w = rand() % 100 +1;
                    this->addEdge(i,j,w);
                }
                
            }
        }
        return;
    }

    while (i < this->N-1) // to make sure there are no isolated vertices and there is a path connecting every edge
    {
        w = rand() % 100 +1;
        this->addEdge(i,i+1,w); // connecting every vertex to the next one 
        
        i++;
    }
    i = nr_e;
    while( i < d){ // add random edges until we hit desired number 
        existingEdge = 0;
        s = rand() % this->N;
        e = rand() % this->N;
        w = rand() % 100 +1;
        if(s != e){ // to avoid having edges that start and end at the same vertex
            for(adjNode* j = adjList[s]; j != nullptr; j = j->next){ // to avoid connecting vertices that are already connected 
                if(j->val == e){
                    existingEdge = 1;
                }
            }
            if(existingEdge == 0){
                this->addEdge(s,e,w);
                i++;
            }
        }
    } 
};