#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V, E;
    vector<int> *adj;
    void DFSHelper(int k, vector<bool> &visited);
public:
    Graph(int V);
    int getV() { return V; }
    int getE() { return E; }
    void addEdge(int u, int v);
    void DFS(int k);
    void BFS(int k);
};

Graph::Graph(int V){
    this->V = V;
    this->E = 0;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }

}

void Graph::DFSHelper(int k, vector<bool> &visited){
    cout << k << " ";
    visited[k] = true;
    for(auto x : adj[k]){
        if(!visited[x]){
            DFSHelper(x, visited);
        }
    }
}

void Graph::DFS(int k){
    vector<bool> visited(V, false);
    DFSHelper(k, visited);
}

int main(){
    Graph g(5);                       
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS starting from vertex 0:\n";
    g.BFS(0);

    cout << "DFS starting from vertex 0:\n";
    g.DFS(0);

    return 0;
}