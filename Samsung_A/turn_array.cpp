#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int map[55][55];
struct st {

    int r, c, s;
};
vector<st> v;

int main() {

    int N, M, K, tmp;
    int r, c, s;

    st s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            cin >> tmp;
            map[i][j] = tmp;

        }
    }

    for (int i = 0; i < K; i++) {

        cin >> r >> c >> s;
        v.push_back({r, c, s});
    }
    

    return 0;
}