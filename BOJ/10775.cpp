#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX_LEN 100001
#define pp pair<int, pair<int, int > > 

using namespace std; 

int parent[MAX_LEN] = {-1, };
int answer = 0;
int G, P, a;

int collapsingFind(int i) {

    int root, trail, lead;
    for (root = i; parent[root] >= 0; root = parent[root])
    
    for (trail = i; trail != root; trail = lead) {
        lead = parent[trail];
        parent[trail] = root;
    }

    return root;
}

bool merge(int i) {
    
    int r1 = collapsingFind(i);
    if (r1 == 0) return false;
    parent[r1] = r1 - 1;
  
    return true;
}

void init() {
    for (int i = 0; i < MAX_LEN; i++) parent[i] = -1;
}
int main() {

    int answer = 0;
    cin >> G;
    cin >> P;
    init();
    for (int i = 0; i < P; i++) {
        cin >> a;
        if (merge(a)) answer++;
        else break;
    }

    cout << answer << endl;
    return 0;
}