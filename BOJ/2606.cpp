#include <iostream>
#include <vector>
#include <queue>
#define MAX_NUM 101

using namespace std; 

vector<vector<int > > v(MAX_NUM);
bool visited[MAX_NUM] = {false, };
int N, answer = 0;

void bfs() {

    queue<int > q;
    visited[1] = true;
    q.push(1);

    while(!q.empty()) {
        
        int from = q.front();
        q.pop();

        for (int i = 0; i < v[from].size(); i++) {
            int to = v[from][i];

            if (visited[to]) continue;  // already visited

            answer++;
            visited[to] = true;
            q.push(to);
        }

        // cout << "---"<< endl;
    }
}

int main() {

    int a, b, t;
    cin >> N;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }    

    bfs();
    cout << answer << endl;
    return 0;
}