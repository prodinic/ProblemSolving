#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#define p pair<int, int >
#define MAX_NUMBER 1001

using namespace std;

int N, M, V;
bool map[MAX_NUMBER][MAX_NUMBER];
bool visited[MAX_NUMBER] = {false, };

void bfs(int a) {

    queue<int > q;
    visited[a] = true;
    q.push(a);
    cout << a << " ";
    while(!q.empty()) {

        int from = q.front();
        q.pop();

        for (int to = 1; to <= N; to++) {

            if (map[from][to]) {
                if (visited[to]) continue;
                
                visited[to] = true;
                q.push(to);
                cout << to << " ";
            }
        }
    }

    cout << endl;
    return;
}

int dfs(int from) {

    visited[from] = true;
    cout << from << " "; 

    for (int to = 1; to <= N; to++) {

        if (map[from][to]) {
            if (visited[to]) continue;
            dfs(to);
        }
    }

    return 0;
}

int main() {

    int a, b;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        
        cin >> a >> b;
        map[a][b] = true;
        map[b][a] = true;
    }

    dfs(V);
    cout << endl;
    memset(visited, false, sizeof(visited));
    bfs(V);

    return 0;
}