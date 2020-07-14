#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX_NUM 51
#define p pair<int, int >

using namespace std;

void printAll(int t, int order[]) {

    for (int i = 0; i < t; i++) {
        cout << order[i] << " ";
    }
    cout << "\n";
}

int main() {

    int t, x, y;
    int order[MAX_NUM];
    for (int i = 0; i < MAX_NUM; i++) {
        order[i] = 1;
    }
    vector<p> v;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for (int i = 0; i < t; i++) {
        int n = 1;
        x = v[i].first;
        y = v[i].second;
        for (int j = 0; j < t; j++) {
            if (i == j) continue; 
            else {
                if (v[j].first > x && v[j].second > y) n++;
                else continue;
            }
        order[i] = n;
        }
    }

    printAll(t, order);
    return 0;
}