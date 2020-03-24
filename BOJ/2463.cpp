#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX_NUM 100005
#define MOD 1000000000

using namespace std;

struct info {
    int from, to; 
    ll cost;
};
ll parent[MAX_NUM];
int N, M;
ll total = 0, answer = 0;
info vi[MAX_NUM];
bool compare(info a, info b) {

    if (a.cost > b.cost) return true;
    else return false;
}

int collapsingFind(int u) {

    if (parent[u] < 0) return u;
    else return parent[u] = collapsingFind(parent[u]);
}

void weightedUnion(int u, int v, int cost) {

    u = collapsingFind(u);
    v = collapsingFind(v);

    int temp = parent[u] + parent[v];

    if (u != v) {
        answer += (-parent[u]) * (-parent[v]) * total; 
        answer %= MOD; 
    
        if (u > v) {
            parent[v] = u;
            parent[u] = temp;
        }
        else {
            parent[u] = v;
            parent[v] = temp;
        }       
    }
    total -= cost; 
}

void init() {
    for (int i = 1; i <= N; i++) parent[i] = -1;  
}

void solve() {

    sort(vi, vi + M, compare);
    // printAll();
    for (int i = 0; i < M; i++) {
        int from = vi[i].from;
        int to = vi[i].to;
        int cost = vi[i].cost;

        weightedUnion(from, to, cost);
    }
    cout << answer << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int u, v;
    ll c;
    info tmp;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        tmp.from = u, tmp.to = v, tmp.cost = c;
        vi[i] = tmp;
        total += c;
    }
    
    init();
    solve();
    
    return 0;
}