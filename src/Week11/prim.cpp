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

struct Edge {
    int u, v, w;
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

    void prim(int u){

    }

public:
    Mst(Graph graph){ 
        totalWeight = 0; 
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
