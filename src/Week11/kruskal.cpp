#include<bits/stdc++.h>
using namespace std;

/**
 * Ý tưởng thật toán:
 * 
 * 1. Sắp xếp tất cả các cạnh theo thứ tự không giảm dần về trọng lượng. 
 * 2. Chọn cạnh nhỏ nhất. Kiểm tra xem nó có tạo thành một chu trình với cây bao trùm
 *  đã hình thành cho đến nay không. Nếu chu trình không được hình thành, hãy bao gồm
 *  cạnh này. Nếu không, hãy loại bỏ nó.
 * 3. Lặp lại bước số 2 cho đến khi có các cạnh (V-1) trong cây mở rộng.
 * 
 * Dùng cấu trúc du liệu union find để hợp cây.
 */

/**
 * Độ phức tạp của thuật toán:
 * 
 * Việc sắp xếp các cạnh mất thời gian O(E * logE). 
 * 
 * Sau khi sắp xếp, chúng tôi lặp lại tất cả các cạnh và áp dụng thuật toán tìm-hợp. 
 * Các hoạt động tìm và hợp có thể mất tối đa thời gian O(logV).
 * 
 * Vì vậy, độ phức tạp tổng thể là thời gian O(E * logE + E * logV). 
 */
struct Edge {
    int u, v, w;
};

class Dsu {
private:
    vector<int> parent;

public:
    Dsu(int n){
        parent.resize(n + 5, 0);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }

    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool join(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        parent[v] = u;
        return true;
    }
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
};

class Mst{
private:
    vector<Edge> edgeList;
    int totalWeight;

    static bool cmp(Edge a, Edge b){ 
        return a.w <= b.w; 
    }

    void kruskal(Graph graph){
        vector<Edge> list = graph.getEdges();
        sort(list.begin(), list.end(), cmp);

        Dsu dsu(graph.getV());

        for(auto x : list){
            if(edgeList.size() == graph.getV() - 1) break;

            if(dsu.join(x.u, x.v)){
                edgeList.push_back(x);
                totalWeight += x.w;
            }
        }
    }

public:
    Mst(Graph graph){ 
        totalWeight = 0; 
        kruskal(graph);
    }

    vector<Edge> getEdges(){ return edgeList; }

    int getWeight(){ return totalWeight; }

};


int main() {
    Graph graph(4);

    graph.addEdge(1, 2, 10);
    graph.addEdge(2, 3, 15);
    graph.addEdge(1, 3, 5);
    graph.addEdge(3, 4, 10);

    Mst mst(graph);

    cout << "Total weight of MST: " << mst.getWeight() << endl;

    cout << "Edges in MST:" << endl;
    for (auto edge : mst.getEdges()) {
        cout << "(" << edge.u << ", " << edge.v << ") - " << edge.w << endl;
    }

}
