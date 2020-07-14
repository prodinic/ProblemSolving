#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#define MAX_NUM 10001

using namespace std;

int N;
vector<vector<int> > v(MAX_NUM);
vector<vector<int> > levels(MAX_NUM);
int orders[MAX_NUM];
int order = 1;
int maximum_width = -1;
int longest_level;
void solve() {

    for (int level = 1; levels[level].size() != 0; level++) {
        if (maximum_width < orders[levels[level].back()] - orders[levels[level].front()]) {
            maximum_width = orders[levels[level].back()] - orders[levels[level].front()];
            longest_level = level;
        }
    }
}
void printAll() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < levels[i].size(); j++) {
            printf("%d ", levels[i][j]);
        }
        printf("\n");
    }
}

void dfs(int s, int level) {

    levels[level].push_back(s);
    for (int i = 0; i < 2; i++) {
        int node = v[s][i];
        if (node != -1) dfs(node, level + 1);
        else continue;
    }
}

void inorderTraverse(int root) {

    if (v[root][0] != -1) inorderTraverse(v[root][0]);
    orders[root] = order;
    order++;
    if(v[root][1] != -1) inorderTraverse(v[root][1]);
}

int main() {

    int parent, left_child, right_child;
    long long int root;
    scanf("%d", &N);
    root = N * (N + 1) / 2;
  
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &parent, &left_child, &right_child);
        v[parent].push_back(left_child);
        if (left_child != -1) root -= left_child;
        v[parent].push_back(right_child);
        if (right_child != -1) root -= right_child;
    }

    inorderTraverse(root);
    dfs(root, 1);
    // printAll();
    solve();
    printf("%d %d\n", longest_level, maximum_width + 1);
    return 0;
}