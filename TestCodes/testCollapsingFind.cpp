#include <iostream>

using namespace std;

int parent[] = {-1, 0, 1, 2, 3, 4, 5};  // degenerated tree

int collapsingFind(int u) {

    if (parent[u] == -1) return u;
    else return parent[u] = collapsingFind(parent[u]);
}

void printAll() {

    for (int i = 0; i < 7; i++) {
        cout << parent[i]<< " ";
    }
    cout << "\n";
    return;
}
int main() {

    collapsingFind(6);
    printAll();

    return 0;
}