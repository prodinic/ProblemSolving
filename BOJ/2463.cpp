#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX_LEN 100001
#define pp pair<int, pair<int, int > > 

using namespace std; 

int parent[MAX_LEN];
int answer = 0;
int N, M, x, y, w;

int find(int i) {

    if (parent[i] == -1) return i;
    else {
        return find(parent[i]);
    }
}

bool merge(int i) {

    int r1 = find(i);
    if (r1 == 0) return false;
    if (r1 == i) parent[i] = i - 1;
 
    return true;
}

void init() {
    for (int i = 0; i < MAX_LEN; i++) {
        parent[i] = -1;
    }
}

bool compare(pp a, pp b) {
    if (a.first < a.first) return true;
    else return false; 
}

int main() {

    vector<pp> v;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> w;
        v.push_back(make_pair(w, make_pair(x, y)));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {

        }
    }
    init();








    return 0;
}