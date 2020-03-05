#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAX_LEN 22

using namespace std;

int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN] = {false, };
priority_queue<pair<int, pair<int, int> > > pq;
pair<int, int> start;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int answer = 0, N;
int cur_weight = 2;

bool compare(pair<int, int> a, pair<int, int> b) {
    
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

int bfs2(int originX, int originY, int destX, int destY) {

    priority_queue<pair<int, pair<int, int> > > pq2;

    pq2.push(make_pair(0, make_pair(originX, originY)));
    visited[originX][originY] = true;

    while(!pq2.empty()) {
        int stage = -pq2.top().first;
        int x = pq2.top().second.first;
        int y = pq2.top().second.second;

        if (x == destX && y == destY) return stage;
        
        pq2.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (visited[nx][ny]) continue;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (map[nx][ny] > cur_weight) continue;

            pq2.push(make_pair(-(stage + 1), make_pair(nx, ny)));
            visited[nx][ny] = true; 
        }
    }

    return -1;
}
void bfs() {

    int new_fishes = 0;
    int cnt = 0;
    vector<pair<int, int > > targets;

    // cout << "priority queue size : " << pq.size() << endl;
    while (!pq.empty() && (-1) * pq.top().first < cur_weight) {
        targets.push_back(make_pair(pq.top().second.first, pq.top().second.second)); 
        pq.pop();   
    }

    while(1) {

        if (cur_weight == cnt) {
            cur_weight++;
            // cout << "cur_weight : " << cur_weight << endl; 
            cnt = 0;
            while (!pq.empty() && (-1) * pq.top().first < cur_weight) {
                targets.push_back(make_pair(pq.top().second.first, pq.top().second.second)); 
                pq.pop();   
            }
        }

        // cout << "target size : " << targets.size() << endl;

        int nearX = -1, nearY = -1;
        int cur_x = start.first, cur_y = start.second;
        int shortest = INT_MAX;

        // find the nearest target
        int idx = -1;
        sort(targets.begin(), targets.end(), compare);
        for (int i = 0; i < targets.size(); i++) {
            
            int target_x = targets[i].first;
            int target_y = targets[i].second;
            // cout << "target_x : "<< target_x << " | target_y : " <<target_y << endl;
            int hops = bfs2(cur_x, cur_y, target_x, target_y);
            memset(visited, false, sizeof(visited));
            if (hops != -1 && hops < shortest) {

                nearX = target_x;
                nearY = target_y;
                shortest = hops;
                idx = i;
            }
        }

        if (idx == -1) return;
        targets.erase(targets.begin() + idx);

        if (nearX != -1 && nearY != -1) {
            cnt++;
            // cout << "cur_x : " << cur_x << " | cur_y : "<< cur_y << " | nearX : " << nearX << " | nearY : "<< nearY << " | len : "<<shortest<< endl; 
            map[cur_x][cur_y] = 0;
            map[nearX][nearY] = 0; 
            start.first = nearX;
            start.second = nearY;
            answer += shortest;

        } 
        else {
            break;
        }
    }
}
int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 0) continue;
            else if (1 <= map[i][j] && map[i][j] <= 6) {
                pq.push(make_pair(-map[i][j], make_pair(i, j)));
            }
            else if (map[i][j] == 9) {
                start.first = i;
                start.second = j;
            }
        }
    }
    // cout << "BFS Start!" << endl;
    if (pq.size() > 0) bfs();

    cout << answer << endl;
    return 0;
}