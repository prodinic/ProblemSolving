#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_LEN 1000001

using namespace std;

int parent[MAX_LEN];
int n, m;
int collapsingFind(int i) {

    int trail, root, lead;
    for (root = i; parent[root] >= 0; root = parent[root])

    for (trail = i; trail != root; trail = lead) {
        lead = parent[trail];
        parent[trail] = root;
        // cout << "test " << endl; 
    }

    return root;
}
int simpleFind(int i) {
    if (parent[i] == i) return i;
    else return parent[i] = simpleFind(parent[i]);
}
void init() {
    for (int i = 0; i <= n; i++) parent[i] = -1;
}
void merge(int i, int j) {
    i = collapsingFind(i);
    j = collapsingFind(j);

    if (i != j) parent[i] = j;
}

int main() {

    int a, b, k;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {

        cin >> k >> a >> b;
        if (k == 0) merge(a, b);
        else {
            a = collapsingFind(a);
            b = collapsingFind(b);
            if (a != b) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }

    return 0;
}