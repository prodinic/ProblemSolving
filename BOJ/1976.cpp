#include <iostream>
#include <vector>
#include <queue>
#define MAX_LEN 201

using namespace std;

int N, M, map[MAX_LEN][MAX_LEN];
int parent[MAX_LEN];
vector<int > v;

int find(int i) {
    
    if (parent[i] == i) return i;
    else return  parent[i] = find(parent[i]);
}
void merge(int i, int j) {
    i = find(i);
    j = find(j);
    if (i != j) parent[j] = i;
}

void init() {
    for (int i = 0; i < MAX_LEN; i++) parent[i] = i;
}
int main() {

    int a;

    cin >> N;
    cin >> M;
    init();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                // if (i < j) merge(i, j);
                // else merge(j, i);
                merge(i, j);
            }
        }
    }    
    for (int i = 0; i < M; i++) {
        cin >> a;
        v.push_back(a - 1);         
    }
    for (int i = 0; i < M - 1; i++) {
        int ni = find(v[i]);
        int nj = find(v[i + 1]);
        if (ni != nj) {
            cout << "NO" << endl;
            return 0;
        }
        // for (int j = i + 1; j < M; j++) {
        //     int ni = find(v[i]);
        //     int nj = find(v[j]);
        //     if (ni != nj) {
        //         cout << "i : "<< i << " | ni : "<<ni << " | j : "<< j << " | nj : "<<nj << endl;
        //         cout << "NO" << endl;
        //         return 0;
        //     }
        // }
    }

    cout << "YES" << endl;
    return 0;
}