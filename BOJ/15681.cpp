#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 100001

using namespace std;

int N, R, Q;
vector<vector<int> > connect(MAX_NUM);
int node_size[MAX_NUM];
int root[MAX_NUM];
vector<vector<int > > child_node(MAX_NUM);

void makeTree(int currentNode, int parent) {

    for (int i = 0; i < connect[currentNode].size(); i++) {
        int child = connect[currentNode][i];
        if (child != parent) {
            child_node[currentNode].push_back(child);
            root[child] = currentNode;
            makeTree(child, currentNode);
        }
    }
}
void countSubtreeNodes(int currentNode) {

    node_size[currentNode] = 1;
    for (int i = 0; i < child_node[currentNode].size(); i++) {
        int child = child_node[currentNode][i];
        countSubtreeNodes(child);
        node_size[currentNode] += node_size[child];
    }
}
int main() {
    
    int v1, v2, v3;
    memset(node_size, 0, sizeof(node_size));
    scanf("%d %d %d", &N, &R, &Q);

    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &v1, &v2);
        connect[v1].push_back(v2);
        connect[v2].push_back(v1);
    }
    root[R] = -1;
    // printf("\n---1\n");
    makeTree(R, root[R]);
    // printf("\n---2\n");
    countSubtreeNodes(R);

    for (int i = 0; i < Q; i++) {
        scanf("%d", &v3);
        // printf("\n---3\n");
        printf("%d\n", node_size[v3]);
        // printf("\n---4\n");
    }
    return 0;
}
