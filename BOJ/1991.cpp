#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX_NUM 27

using namespace std;

int N;
vector<vector<int > > trees(MAX_NUM);

void preorder(int src) {
    
    int left_child = trees[src][0];
    int right_child = trees[src][1];
    printf("%c", src + 'A');
    if (left_child != -1) preorder(left_child);
    if (right_child != -1) preorder(right_child); 
}

void inorder(int src) {

    int left_child = trees[src][0];
    int right_child = trees[src][1];
    if (left_child != -1) inorder(left_child);
    printf("%c", src + 'A');
    if (right_child != -1) inorder(right_child); 
}

void postorder(int src) {

    int left_child = trees[src][0];
    int right_child = trees[src][1];
    if (left_child != -1) postorder(left_child);
    if (right_child != -1) postorder(right_child); 
    printf("%c", src + 'A');    
}

int main() {

    scanf("%d", &N);
    char parent, left_child, right_child;
    for (int i = 0; i < N; i++) {
        cin >> parent >> left_child >> right_child;
        if (left_child != '.') trees[parent - 'A'].push_back(left_child - 'A');
        else trees[parent - 'A'].push_back(-1);
        if (right_child != '.') trees[parent - 'A'].push_back(right_child - 'A');
        else trees[parent - 'A'].push_back(-1);
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    printf("\n");
    return 0;
}