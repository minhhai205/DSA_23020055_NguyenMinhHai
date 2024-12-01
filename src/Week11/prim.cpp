#include<bits/stdc++.h>
using namespace std;

/**
 * Ý tưởng thuật toán:
 * Thuật toán Prim lại kết nạp từng đỉnh vào đồ thị theo tiêu chí: đỉnh được nạp vào tiếp theo 
 * phải chưa được nạp và gần nhất với các đỉnh đã được nạp vào đồ thị.
 * 
 * Thuật toán bao gồm các bước sau:
 * 1. Khởi tạo tập S là cây khung hiện tại, ban đầu S chưa có đỉnh nào.
 * 
 * 2. Khởi tạo mảng D trong đó Di là khoảng cách ngắn nhất từ đỉnh i đến 1 đỉnh đã được kết nạp vào tập S,
 *   ban đầu D[i] = +∞
 * 
 * 3. Lặp lại các thao tác sau n lần(n là số cạnh của đồ thị):
 *   - Tìm đỉnh u không thuộc S có Du nhỏ nhất, thêm u vào tập S.
 *   - Xét tất cả các đỉnh v kề u, cập nhật Dv = min(Dv, Wu_v) với Wu_v là trọng số cạnh u-v. 
 *   Nếu Dv được cập nhật theo Wu_v thì đánh dấu Parent(v) = u.
 * 
 * 4. Thêm cạnh u - Parent(u) vào tập cạnh thuộc cây khung nhỏ nhất.
 */

/**
 * Độ phức tạp của thuật toán:
 * 
 * Duyệt qua tất cả các đỉnh và cạnh:
 *   - Duyệt qua các đỉnh: O(V).
 *   - Mỗi đỉnh duyệt qua danh sách kề của nó: O(E).
 *   - Các thao tác cập nhật priority queue: O(log V) với mỗi cạnh.
 * Do đó, tổng độ phức tạp là: O((V + E) log V)
 */

struct Edge {
    int u, v, w;
};


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
};

class Mst{
private:
    vector<Edge> edgeList;
    int totalWeight;

    void prim(int s, Graph graph){
        vector<vector<pair<int, int>>> adj = graph.getAdj();
        
        int dis[graph.getV() + 1];  // mảng lưu khoảng cách của toàn bộ đỉnh

        for (int i = 1; i <= graph.getV(); i++) dis[i] = INT_MAX;

        int parent[graph.getV() + 1];
        
        // các phần tử lưu trong priority queue sẽ có dạng pair<dis[u],u>
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        dis[s] = 0;
        q.push({0, s});

        while(!q.empty()){
            auto top = q.top(); q.pop();

            int currDis = top.first, u = top.second;

            if(currDis != dis[u]) continue;

            totalWeight += dis[u]; 
            dis[u] = INT_MIN;

            if(u != s) {
                edgeList.push_back({parent[u], u, currDis});
            }

            for(auto it : adj[u]){
                int v = it.first, w = it.second;
                if(w < dis[v]){
                    dis[v] = w;
                    parent[v] = u;
                    q.push({w, v});
                }
            }
        }
    }

public:
    Mst(Graph graph){ 
        totalWeight = 0; 
        prim(1, graph);
    }

    vector<Edge> getEdges(){ return edgeList; }

    int getWeight(){ return totalWeight; }

};


int main() {
    Graph graph(7);  
    graph.addEdge(1, 2, 7);
    graph.addEdge(1, 3, 6);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 9);
    graph.addEdge(2, 5, 7);
    graph.addEdge(3, 5, 9);
    graph.addEdge(4, 5, 15);
    graph.addEdge(4, 6, 8);
    graph.addEdge(5, 6, 5);
    graph.addEdge(5, 7, 10);
    graph.addEdge(6, 7, 2);

    Mst mst(graph);

    cout << "Tổng trọng số của cây khung nhỏ nhất: " << mst.getWeight() << endl;

    for (const auto& edge : mst.getEdges()) {
        cout << "Cạnh: " << edge.u << " - " << edge.v << " với trọng số: " << edge.w << endl;
    }

}