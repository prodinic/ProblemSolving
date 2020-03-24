#include <iostream>
#define MAX_LEN 1000010
#define ll long long 

using namespace std;

ll parent[MAX_LEN];
int n, m;

void init() {
    for (int i = 0; i < MAX_LEN; i++) parent[i] = -1;
}

int collapsingFind(int u) {
    if (parent[u] < 0) return u;
    else return parent[u] = collapsingFind(parent[u]);
}

void merge(int u, int v) {

    u = collapsingFind(u);
    v = collapsingFind(v);

    ll temp = parent[u] + parent[v];
    // cout << temp << endl;
    // if v has much more ranks than u
    if (parent[u] > parent[v]) {
        parent[u] = v;
        parent[v] = temp;
    }
    else {
        parent[v] = u;
        parent[u] = temp;
    }

    return; 
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, k;
    cin >> n >> m;
    
    init();
    
    for (int i = 0; i < m; i++) {

        cin >> k >> a >> b;
        if (k == 0) merge(a, b);
        else {
            if (collapsingFind(a) != collapsingFind(b)) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }

    return 0;
}