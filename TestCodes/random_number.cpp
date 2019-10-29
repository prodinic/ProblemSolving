#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 4; i++) {
        cout<<(rand() % 76) + 7<<endl;
    }

    return 0;
}