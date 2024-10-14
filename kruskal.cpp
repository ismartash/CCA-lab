#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class ash {
    int v;
    vector<vector<int>> edges;
    int parent[100];
    int rank[100];
    public:
    ash(int  n) {
        v= n;
        for (int i = 0; i < v; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    void addedge(int u, int v, int weight) {
        edges.push_back({weight, u, v});
    }

    int find(int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unions(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }

    void kruskal() {
        sort(edges.begin(), edges.end());
        int mst= 0;
        cout << "edges in mst" << endl;
        for (int i = 0; i < edges.size(); i++) {
            int weight = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if (find(u) != find(v)) {
                unions(u, v);
                mst+= weight;
                cout << u << " --> " << v << " =" << weight << endl;
            }
        }

        cout << "total weight of mst: " << mst << endl;
    }
};

int main() {
    int n, m;
    cout<< "enter no of vertices"<<endl;
    cin>>n;
    ash g(n);
    cout << "enter  number of edges"<<endl;
    cin>>m;
    cout <<"enter the edges (source dest weigt):"<<endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addedge(u, v, weight);
    }
    g.kruskal();
    return 0;
}