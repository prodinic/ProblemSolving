#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_LEN 1000001
#define p pair<int, int >

using namespace std; 

int F, S, G, U, D;
bool visited[MAX_LEN] = {false, };
void bfs(){

    queue<p> q;

    visited[S] = true;
    q.push(make_pair(S, 0));

    while(!q.empty()) {

        int from = q.front().first;
        int step = q.front().second;
        q.pop();

        if (from == G) {
            cout << step << endl;
            return; 
        }

        int up = from + U;
        int down = from - D;
        
        if (up <= F && visited[up] == false) {
            visited[up] = true;
            q.push(make_pair(up, step + 1));
        } 

        if (down >= 1 && visited[down] == false) {
            visited[down] = true;
            q.push(make_pair(down, step + 1));
        }  
    }

    cout << "use the stairs" << endl;
    return;
}
int main() {

    cin >> F >> S >> G >> U >> D;
    bfs();
    return 0;
}