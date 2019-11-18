#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define INF 987654321
#include <set>

using namespace std;

int ans;
bool chk[10] = {false, };
int N;
set<int> visited;
vector<int> p;

vector<vector<int> > edge(10);

void dfs(int v, set<int>& s) {
    for (int next : edge[v]) {
        if (visited.find(next) == visited.end() && s.find(next) != s.end()) {
            visited.insert(next);
            dfs(next, s);
        }
    }
}
void check(int bit) {

    set<int> a, b;
    int aval, bval;
    aval = bval = 0;

    for (int i = 0; i < N; i++) {
        int v = (1 << i);

        if (bit & v) {
            a.insert(i);
            aval += p[i];
        }
        else {
            b.insert(i);
            bval += p[i];
        }
    }
    visited.clear();
    visited.insert(*a.begin()); // insert the value of iterator pointing out
    dfs(*a.begin(), a);
    if (visited != a) return;

    visited.clear();
    visited.insert(*b.begin()); // insert the value of iterator pointing out
    dfs(*b.begin(), b);
    if (visited != b) return;

    ans = min(ans, abs(aval - bval));        

}
int main() {

    ans = INF;
    queue<int> q;
    int tmp, tmp2;
    cin >> N;
    int tot = 0;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        tot += tmp;
        p.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            cin >> tmp2;
            edge[i].push_back(tmp2 - 1);
        }
    }

    for (int bit = 1; bit + 1 < (1 << N); bit++) {
        check(bit);
    }

    if (ans == INF) ans = -1;
    
    cout<<ans<<endl;

    // for (int i = 0; i < N; i++) {
        
    //     q.push(i);
    //     chk[i] = true;
    //     int subtot = 0;
        
    //     while(!q.empty()) {

    //         int from = q.front();
    //         q.pop();
    //         subtot += p[from];
            
    //         if (abs(abs(tot - subtot) - subtot) <= res) {
    //             cout << "from : "<<from<<" | abs(tot - subtot) : "<<abs(tot - subtot)<<" | subtot :"<<subtot<<endl;

    //             res = abs(abs(tot - subtot) - subtot);
    //         }

    //         if (checkLastOne() == 1) continue;

    //         for (int j = 0; j < v[from].size(); j++) {
                
    //             int to = v[from][j] - 1;
    //             if (chk[to] == true) continue;

    //             cout << "from : "<<from<<" | to : "<<to<<endl;
    //             q.push(to);
    //             chk[to] = true;
    //         }            
    //     }

    //     memset(chk, false, sizeof(chk));
    //     cout << "res : "<<res<<endl;
    // }


    return 0;
}