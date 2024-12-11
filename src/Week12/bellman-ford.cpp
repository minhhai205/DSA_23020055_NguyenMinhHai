#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int x, y, w;
};

class Graph{
private:
    int V;
    int E;
    vector<Edge> edgeList;
public:
    Graph(int v){ V = v; E = 0; }

    int getV() { return V; }

    int getE() { return E; }

    vector<Edge> getEdges(){ return edgeList; }

    void addEdge(int u, int v, int w){
        edgeList.push_back({u, v, w});
        ++E;
    }

    vector<int> Bellman_Ford(int s){
        vector<int> d(V + 1, INT_MAX);
        d[s] = 0;

        for(int i = 1; i <= V - 1; i++){
            for(int j = 0; j < E; j++){
                Edge tmp = edgeList[j];
                int x = tmp.x, y = tmp.y, w = tmp.w;
                if(d[x] < INT_MAX){
                    d[y] = min(d[y], d[x] + w);
                }
            }
        }

        for (int j = 0; j < E; j++) {
            Edge tmp = edgeList[j];
            int x = tmp.x, y = tmp.y, w = tmp.w;

            if (d[x] < INT_MAX && d[x] + w < d[y]) {
                cout << "Có chu trình âm!" << endl;
                return {};
            }
        }
        return d;
    }
};


int main() {
   
}