#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
#include <queue>
#include <cstdlib>
#include <string.h>

using namespace std; 

set<int> unsafe_cities;
set<int> zombie_cities;
vector<vector<int > > m(100001);
int hops[100001] = {-1, };
bool visited[100001] = {false, };
long long dp[100001];
int N, M, K, S;
long long int answer = LLONG_MAX;
int p, q;
set<int>::iterator it, it2;

void DFS(int from, int total) {

    visited[from] = true;

    if (total < answer && from == N) {
        answer = total;
        return;
    }

    for (int i = 0; i < m[from].size(); i++) {
        int to = m[from][i];

        if (visited[to] == true) continue;
        if (zombie_cities.count(to) != 0) continue;

        if (to != N) {
            if (unsafe_cities.count(to) != 0) DFS(to, total + q);
            else DFS(to, total + p);
        }
        else {
            DFS(to, total);
        }
        visited[to] = false;
    }
}

void DFS2(int from, int hop) {
    // Input :
    // Output :
    // Description : check if it is dangered or not

    if (hops[from] != -1 && hop <= hops[from]) return;
       
    hops[from] = hop;

    if (hop == 0) return;
    
    for (int i = 0; i < m[from].size(); i++) {
        int unsafe_city = m[from][i];

        if (unsafe_cities.count(unsafe_city) != 0) continue;
        if (zombie_cities.count(unsafe_city) != 0) continue;
        
        unsafe_cities.insert(unsafe_city);
        DFS2(unsafe_city, hop - 1);
    }
}

void BFS() {

    priority_queue<pair<long long, int > > pq;
    pq.push(make_pair(0, 1));

    while(!pq.empty()) {

        int from = pq.top().second;
        long long cost = -pq.top().first;
        int len = m[from].size();
        pq.pop();
        
        if (dp[from] >= 0) continue;
        dp[from] = cost; 

        for (int i = 0; i < len; i++) {
            long long to = m[from][i];
            long long cur_price;
            if (unsafe_cities.count(to) != 0) cur_price = q;
            else cur_price = p;

            if (zombie_cities.count(to) != 0) continue;
            if (dp[to] >= 0) continue;

            pq.push(make_pair(-(cost + cur_price), to));
        }
    }

}
int main() {

    int t, a ,b;

    cin >> N >> M >> K >> S;
    cin >> p >> q;

    for (int i = 0; i < K; i++) {
        
        cin >> t;
        zombie_cities.insert(t);
        visited[t] = true;
    }

    for (int i = 0; i < M; i++) {

        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    
    for (it = zombie_cities.begin(); it != zombie_cities.end(); ++it) {
        int zombie_city = *it;
    
        DFS2(zombie_city, S);      
    }

    // cout << "Size of unsafe_cities : " << unsafe_cities.size() << endl;
    
    memset(dp, -1, sizeof(dp));
    cout << "---" << endl;
    BFS();
    cout << "+++" << endl;

    cout << dp[N] << endl;

    return 0;
}