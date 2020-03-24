#include <stdio.h>
#define MAX_NUM 100001

int parent[MAX_NUM];

int collapsingFind(int u) {

    if (parent[u] == -1) return u;
    else return parent[u] = collapsingFind(u); 
}
bool isPossible(int u) {

    u = collapsingFind(u);
    if (u == 0) return false;
    else {
        parent[u] = u - 1;
        return true;
    }
}

void init(int G) {
    for (int i = 0; i <= G; i++) parent[i] = -1;
}

int main() {

    int G, P, answer = 0, a;
    scanf("%d", &G);
    getchar();
    scanf("%d", &P);
    getchar();    
    init(G);
    printf("%d %d\n", G, P);
    for (int i = 0; i < P; i++) {
        scanf("%d", &a);
        getchar();    
        if(isPossible(a)) answer++;
        else break;
    }   

    printf("%d\n", answer);
    return 0;
}