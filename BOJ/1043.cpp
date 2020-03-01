#include <iostream>
#include <vector>
#include <set>
#define MAX_NUM 51

using namespace std;

int N, M;
int H;

set<int> s;
set<int>::iterator it;
// vector<int> people;
vector<int> party_people;
vector<vector<int > > party(MAX_NUM);
vector<vector<int > > v(MAX_NUM);
int parent[MAX_NUM];
bool visited[MAX_NUM] = {false, };

void initGraph() {

    for (int i = 0; i < party_people.size(); i++) {
        int from = party_people[i];

        for (int j = i + 1; j < party_people.size(); j++) {
            int to = party_people[j];

            v[from].push_back(to);
            v[to].push_back(from);
        }
    }
    return;
}


int find(int u) {

    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}


void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (u != v) {
        parent[v] = u;
    }
    
    return;
}

int dfs(int from) {

    visited[from] = true;

    for (int i = 0; i < v[from].size(); i++) {
        int to = v[from][i];
        // cout << "from : "<< from <<" | to : " << to << endl; 

        if (visited[to] == true) continue;

        merge(from, to);
        dfs(to);
        // visited[to] = false;
    }

}

int main() {

    int answer = 0, tmp;

    cin >> N >> M;
    cin >> H;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < H; i++) {
        cin >> tmp;
        s.insert(tmp);
    }

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {

            cin >> tmp;
            party[i].push_back(tmp);
            party_people.push_back(tmp);
            
        }
        if (num > 1) initGraph();
        party_people.clear();    
    }

    // cout << "knowing people : ";
    for (it = s.begin(); it != s.end(); it++) {
        // cout << *it << " ";
        dfs(*it);
    }
    // cout << endl;

    for (int i = 0; i < M; i++) {
        bool flag = true;

        for (int j = 0; j < party[i].size(); j++) {
            int point = party[i][j];

            if (s.count(parent[point]) != 0) {
                flag = false;
                break;
            }
        }

        if (flag) answer++;
    }

    if (H == 0) {
        cout << M << endl;
    }
    else {
        cout << answer << endl;
    }
    return 0;
}