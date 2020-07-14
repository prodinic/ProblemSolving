#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX_NUM 50

using namespace std;

int N;
vector<int> v;
vector<int> record;
bool visited[MAX_NUM];

void printAll(vector<int>& temp) {
    for (int i = 0; i < temp.size(); i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

void dfs(int s) {
    if (record.size() > 6) return;
    else if (record.size() == 6) {
        printAll(record);
        return;
    }
    else {
        // int len = v.size();
        for (int i = 0; i < v.size(); i++) {
            int num = v[i];
            if (visited[num]) continue;
            if (record.back() >= num) continue; 
            // printf("top : %d | num : %d\n", record.back(), num);
            record.push_back(num);
            visited[num] = true;
            dfs(num);
            record.pop_back();
            visited[num] = false;
        }
    }
}

int main() {
    int a;
    memset(visited, false, sizeof(visited));
    while(1) {
        scanf("%d", &N);
        if (N == 0) return 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &a);
            v.push_back(a);
        }
        // printf("---\n");
        // printAll(v);
        // printf("---\n");
        for (int i = 0; i < N; i++) {
            int s = v[i];
            record.push_back(s);
            visited[s] = true;
            dfs(s);
            record.pop_back();
            visited[s] = false;
        }
        printf("\n");
        v.clear();
    }
    return 0;
}