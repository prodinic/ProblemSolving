#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// when we have to get permutation, do while statement is useful!

int main() {

    vector<int> v;

    for (int i = 0; i < 5; i++) {
        v.push_back(i);
    }
    
    do {
        
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        
        cout << endl;

    } while(next_permutation(v.begin() + 1, v.end()));

    return 0; 
}