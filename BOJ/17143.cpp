#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_LEN 101

using namespace std; 

int R, C, M;
struct info {

    int x, y;
    int dir;
    int speed;
    int weight;

};
info shark;
vector<info> v;
int nx, ny, ns, nd;
bool compare(info a, info b) {

    if (a.x == b.x) {
        return a.y < b.y;
    }
    else {
        return a.x < b.x; 
    }
}

void move(int x, int y, int speed, int dir) {

    nx = -1;
    ny = -1;
    ns = -1;
    nd = -1;

    switch (dir) {
        
        // upward
        case 1 :

            for (int i = 0; i < speed; i++) {

                if (x == 1) {
                    dir = 2;
                    move(x, y, speed - i, dir);
                    return;
                } 
                else {
                    x -= 1;
                }
            }
            break;

        // downward
        case 2 : 

            for (int i = 0; i < speed; i++) {

                if (x == R) {
                    dir = 1;
                    move(x, y, speed - i, dir);
                    return;
                }
                else {
                    x += 1;
                }
            }
            break;

        // right
        case 3 :

            for (int i = 0; i < speed; i++) {

                if (y == C) {
                    dir = 4; 
                    move(x, y, speed - i, dir);
                    return;
                }
                else {
                    x += 1;
                }
            }
            break;

        // left
        case 4 :

            for (int i = 0; i < speed; i++) {

                if (y == 1) {
                    dir = 3;
                    move(x, y, speed - i, dir);
                    return;
                }
                else {
                    x -= 1;
                }
            }
            break;

        default :

            break;
    }
    
    nx = x;
    ny = y;
    nd = dir;
    ns = speed;
}
int main() {

    int r, c, s, d, z;
    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {

        cin >> r >> c >> s >> d >> z;
        shark.x = r;
        shark.y = c;
        shark.dir = d;
        shark.speed = s;
        shark.weight = z;
        v.push_back(shark);
    }

    // sorted by x and y ordinates after they move in a second
    int time = c;  
    while (time--) {

        for (int i = 0; i < v.size(); i++) {
            move(v[i].x, v[i].y, v[i].speed, v[i].dir);
            v[i].x = nx;
            v[i].y = ny;
            v[i].dir = nd;
        }

        sort(v.begin(), v.end(), compare);
        cout << "v size : "<<v.size() << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << "x : "<<v[i].x << " | y : "<<v[i].y << " | speed : " <<v[i].speed << " | dir : "<< v[i].dir << " | weight : "<<v[i].weight<< endl;
        }
    }





    return 0;
}