#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {

    bitset<10> bit;

    cout<<"define bit : "<<bit<<endl;
    cout<<"----------------------"<<endl;

    bit.reset();
    cout<<"bit.reset() : "<<bit<<endl; 
    cout<<"----------------------"<<endl;

    cout<<"current bit status : "<<bit<<endl;
    cout<<"bit.all() : "<<bit.all()<<endl;
    cout<<"----------------------"<<endl;

    bit.set();
    cout<<"bit.set() : "<<bit<<endl; 
    cout<<"----------------------"<<endl;

    cout<<"current bit status : "<<bit<<endl;
    cout<<"bit.all() : "<<bit.all()<<endl;
    cout<<"----------------------"<<endl;

    int a = 3;
    for (int b = 1; b + 1 < (1 << 6); b++) {
        cout<< (b & a) <<endl;
    } // Cause a is considered as 00000011, each bit of b is multiplied by each bit of a at the same time in which they have same index.
    
    return 0;
}