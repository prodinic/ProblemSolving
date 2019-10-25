#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define long long int ll

using namespace std;

// MST : Minimum Spanning Tree
// Question : 잘 모르겠다

int main() {

    int T;
    int N, M;
    int a, b;

    int row = 1001;

    cin>>T; 
    vector<vector<int > > v(row);

    for (int i = 0; i < T; i++) {
        cin >> N >> M;

        for (int j = 1; j <= N; j++) {
            
            for (int k = 1; k < N; k++) {

                if (k == j) {   // check return edge
                    continue;
                }
                else {
                    v[j].push_back(k);
                }
            }
            
        }

        for (int j = 0; j < M; j++) {
            cin >> a >> b; // get both cities

            for (int k = 0; k < v[j].size(); k++) {

                if (v[a][k] == b || v[b][k] == a) { // erase both ways
                    v[a][k] = 0;
                    v[b][k] = 0;
                    break;
                } 
                else {
                    continue;
                }
            }
        }

        v.clear();
    }

    return 0;
}