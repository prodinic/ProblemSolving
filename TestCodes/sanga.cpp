	
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define MOD 1000000000
using namespace std;

int n, m;
long long tCost = 0;
long long ret = 0;
class Edge{
public:
    int i, j ,w;
    Edge(int i, int j, int w):i(i),j(j),w(w){}
    bool operator < (const Edge &e) const {
        return w > e.w;
    }
};
vector<Edge> edges;
int vRoot[MAX] = {0, };
long long groupSize[MAX] = {0, };

int findRoot(int v){
    if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
}

void reverseKruskal(){
    for(int i = 1; i <= n; i++){
        vRoot[i] = i;
        groupSize[i] = 1;
    }
    sort(edges.begin(), edges.end());
    for(Edge e : edges){
        int rootI = findRoot(e.i);
        int rootJ = findRoot(e.j);
        if(rootI != rootJ){
            ret += groupSize[rootI] * groupSize[rootJ] * tCost;
            ret %= MOD;
            vRoot[rootJ] = rootI;
            groupSize[rootI] += groupSize[rootJ];
        }
        tCost -= e.w;
    }
    cout << ret << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back(Edge(x, y, w));
        tCost += w;
    }
    reverseKruskal();
    return 0;
}