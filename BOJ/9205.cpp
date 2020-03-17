#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#define p pair<int, int >
#define pp pair<pair<int, int >, bool >
#define MAX_LEN 65536

using namespace std;

p start, dest;
vector<pp> store;

int getDistance(int x, int y, int nx, int ny) {

    return abs(x - nx) + abs(y - ny);
}

void bfs() {

    queue<p> q;
    q.push(start);

    while(!q.empty()) {
        p from;
        from.first = q.front().first;
        from.second = q.front().second;
        q.pop();

        if (getDistance(from.first, from.second, dest.first, dest.second) <= 1000) {
            cout << "happy" << endl;
            return;
        }

        for (int i = 0; i < store.size(); i++) {
            p to;
            to.first = store[i].first.first;
            to.second = store[i].first.second;
            bool flag = store[i].second;

            if (flag) continue; // already visited
            if (getDistance(from.first, from.second, to.first, to.second) > 1000) continue; // too far

            store[i].second = true;
            q.push(to);
        }
    }
    cout << "sad" << endl;
    return;
}

int main() {

    int n, t, x, y;

    cin >> t;

    while(t--) {

        cin >> n;
        cin >> start.first >> start.second; 
        start = make_pair(start.first, start.second);
        for (int i = 0; i < n; i++) {
            p a;
            cin >> a.first >> a.second;
            a = make_pair(a.first, a.second);
            store.push_back(make_pair(a, false));
        } 
        cin >> dest.first >> dest.second;
        dest = make_pair(dest.first, dest.second);
        bfs();
        store.clear(); 
    }

    return 0;
}