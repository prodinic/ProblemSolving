#include <iostream>
#include <vector>

using namespace std; 

int N, M;
vector<vector<int> > m(1001);
int parent[1001];
int level[1001];

void swap(int* a, int* b) {

    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}

void init() {
    // 설명 : parent 배열과 level 배열을 초기화한다.

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        level[i] = 1;
    }
}

int find(int u) {
    // 설명 : 부모 노드를 찾습니다.

    if (u == parent[u])
        return u;

    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (u == v) 
        return;

    if (level[u] > level[v])
        swap(u, v); // 부모 노드의 위치를 바꿉니다

    // 항상 v의 깊이가 더 깊거나 일정한 상태에서 u노드의 부모를 v로 설정한다. 다시 말해, 깊이가 더 긴 그래프에 높이가 낮은 그래프를 합친다.
    parent[u] = v;

    if (level[u] == level[v])
        ++level[v];
}

int main() {

    int u, v;
    
    cin >> N >> M;
    int answer = 0;

    init(); // level과 parent 배열을 초기화한다.
            
    for (int i = 0; i < M; i++) {

        cin >> u >> v;

        merge(u, v);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) answer++;
    }

    cout << answer << endl;

    return 0;
}