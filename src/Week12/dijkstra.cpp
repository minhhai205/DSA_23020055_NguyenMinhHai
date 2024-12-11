#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    int E;
    vector<vector<pair<int, int>>> adj;
public:
    Graph(int v){ 
        adj.resize(v + 1);
        V = v; 
        E = 0; 
    }

    int getV() { return V; }

    int getE() { return E; }

    vector<vector<pair<int, int>>> getAdj(){ return adj; }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        ++E;
    }

    vector<int> dijkstra(int u){

        vector<int> d(V + 1, INT_MAX);
        d[u] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.push({0, u});
        while(!Q.empty()){
            pair<int, int> pe = Q.top(); Q.pop();
            int u = pe.second, length = pe.first;
            if(d[u] < length) continue;
            for(auto x : adj[u]){
                int v = x.first;
                int w = x.second;
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    Q.push({d[v], v});
                }
            }
        }
        return d;
    }
};


int main() {
    int n = 5;
    Graph g(n);

    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 3);

    vector<int> distances = g.dijkstra(1);

    for (int i = 1; i <= n; ++i) {
        cout << "Khoảng cách từ 1 đến " << i << ": ";
        if (distances[i] == INT_MAX) 
            cout << "INF" << endl;
        else
            cout << distances[i] << endl;
    }

    return 0;
}