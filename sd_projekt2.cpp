#include "Prim.h"
#include <chrono>
#include <fstream>

int main()
{
    int n = 1000; // number of vertices
    int density = 100;
    //Graph_list G(n);
    //G.randomize(density);
    //G.display();
    //Prim_pq(&G,1);
    //Prim_heap(&G,1);
    //Heap H(3);
    //H.insert(2,9);
    //H.insert(1,51);
    
    //cout << H.extractMin()->key << endl;

    // możliwy problem z pozycjami w kopcu
    fstream plik;
    double sum=0;
    plik.open("data.csv", fstream::out | fstream::trunc);
    if(plik.is_open()){
        plik << "V= " << n << " Density= " << density << "%\n";
        //plik << "Time(microseconds): \n";
        for(int i = 0; i < 100; i++){
            cout << i << endl; // progress
            Graph_list G(n);
            G.randomize(density);
            auto start = chrono::high_resolution_clock::now();
            Prim_pq(&G,0);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
            //cout << duration.count() << endl;
            //plik << duration.count() << endl;
            sum += duration.count();
        }
        cout << "Average time (microseconds): " << sum/100 << endl;
        plik << "Average time (microseconds): " << sum/100 << endl;
        plik.close();
    }
    else cout << "Failed to open file." << endl;

    return 0;
}