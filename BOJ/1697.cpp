#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_LEN 100001

using namespace std;

int N, K;
int answer = 0;
vector<int > v(MAX_LEN, INF);

void bfs(int from) {

    queue<pair<int, int > > q;
    q.push(make_pair(from, 0)); 

    while(!q.empty()) {
        int to = q.front().first; 
        int step = q.front().second;
        q.pop();

        if (to == K && v[to] > step) {
            v[to] = step;
            return;
        }

        if (0 <= to - 1 && to - 1 <= 100000) {
            if (v[to - 1] == INF) {
                v[to - 1] = step + 1;
                q.push(make_pair(to - 1, step + 1));
            }
        }
        if (0 <= to + 1 && to + 1 <= 100000) {
            if (v[to + 1] == INF) {
                v[to + 1] = step + 1;
                q.push(make_pair(to + 1, step + 1));      
            }
        }
        if (0 <= to * 2 && to * 2 <= 100000) {
            if (v[to * 2] == INF) {
                v[to * 2] = step + 1;
                q.push(make_pair(to * 2, step + 1));            
            }
        }
    }

}

int main() {

    cin >> N >> K;
    bfs(N);
    cout << v[K] << endl;
    return 0;
}