#include <iostream>
#include <climits>
using namespace std;

void prims(int v, int graph[20][20]) {
    int parent[v];  
    int key[v];    
    bool mst[v];    
    for (int i = 0; i < v; i++) {
        key[i] = INT_MAX;
        mst[i] = false;
    }
    key[0] = 0;   
    parent[0] = -1;   
    for (int count = 0; count < v - 1; count++) {
        int min = INT_MAX, idx;
        for (int j = 0; j < v; j++)
            if (mst[j] == false && key[j] < min)
            {
                min = key[j];
                idx = j;
            }
        int u = idx;
        mst[u] = true;
        for (int V = 0; V < v; V++)
            if (graph[u][V] && mst[V] == false && graph[u][V] < key[V]) {
                parent[V] = u;
                key[V] = graph[u][V];
            }
    }

    cout << "edge \t weight\n";
    int mstwt=0;
    for (int i = 1; i < v; i++)
    {
        cout << parent[i] << " - " << i << "\t" <<graph[i][parent[i]]<<"\n";
        mstwt+=graph[i][parent[i]];
    }
    cout<<"mst weight: "<<mstwt<<endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[20][20];
    cout << "enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++)
    {
    for (int j = 0; j < V; j++)
    {
            cin >> graph[i][j];
    }
    }
    prims(V, graph);
    return 0;
}
