#include<bits/stdc++.h>
using namespace std;

/**
 * u: đỉnh 1
 * v: đỉnh 2
 * w: trọng số
 */
class Graph{
private:
    int V, E;
    vector<pair<int, int>> *adj;
    void DFSHelper(int k, vector<bool> &visited);
public:
    Graph(int V);
    int getV() { return V; }
    int getE() { return E; }
    void addEdge(int u, int v, int w);
    void DFS(int k);
    void BFS(int k);
};

Graph::Graph(int V){
    this->V = V;
    this->E = 0;
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    ++E;
}
void Graph::BFS(int k){
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(k);
    visited[k] = true;

    while(!q.empty()){
        int s = q.front();
        q.pop();

        cout << s << " ";

        for(auto x : adj[s]){
            if(!visited[x.first]){
                q.push(x.first);
                visited[x.first] = true;
            }
        }
    }

}

void Graph::DFSHelper(int k, vector<bool> &visited){
    cout << k << " ";
    visited[k] = true;
    for(auto x : adj[k]){
        if(!visited[x.first]){
            DFSHelper(x.first, visited);
        }
    }
}

void Graph::DFS(int k){
    vector<bool> visited(V, false);
    DFSHelper(k, visited);
}

int main(){
   
}