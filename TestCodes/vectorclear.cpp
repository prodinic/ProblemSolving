#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v(5, 3);
    cout << "size of v : "<< v.size();
    v.clear();
    cout << "size of v : "<< v.size();




    return 0;
}