#include <algorithm>
#include <iostream>
#include <memory.h>

#define MAX_N 2
using namespace std; 

int rectangle[4][4];
int answer[8][3], temp[8][3];
int min_stage = 9;

int count() {
    // count matched number in rectangle
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (rectangle[i][j] == i * 4 + j + 1) cnt++;
        }
    }

    return cnt;
}

void rotate(int direction, int pos) {
    // rotate by 1 hop for specific direction

    int t;
    // move horizontally
    if (direction == 1) {

        t = rectangle[pos - 1][3];
        for (int i = 3; i > 0; i--) {
            rectangle[pos - 1][i] = rectangle[pos - 1][i - 1];
        }
        rectangle[pos - 1][0] = t;
    }
    // move vertically
    else {
        
        t = rectangle[3][pos - 1];
        for (int i = 3; i > 0; i--) {
            rectangle[i][pos - 1] = rectangle[i - 1][pos - 1];
        }
        rectangle[0][pos - 1] = t;
    }
}

void func(int stage) {
    // check every options
    if (stage >= min_stage || stage > MAX_N) return;

    int cnt = count();

    if (cnt == 16) {
        memcpy(answer, temp, sizeof(answer));
        min_stage = stage;
        return;
    }

    if (stage + 2 >= min_stage && stage + 2 > MAX_N && cnt < 12) return;
    if (stage + 3 >= min_stage && stage + 3 > MAX_N && cnt < 9) return;
    if (stage + 4 >= min_stage && stage + 4 > MAX_N && cnt < 6) return;


    for(int dir = 1; dir < 3; dir++) {
        for (int pos = 1; pos <= 4; pos++) {
            for (int hop = 1; hop <= 3; hop++) {
                rotate(dir, pos);
                temp[stage][0] = dir;
                temp[stage][1] = pos;
                temp[stage][2] = hop;
                func(stage + 1);
            }
            rotate(dir, pos);
        }
    }
}
int main() {

    int n;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
            cin >> n;
            rectangle[i][j] = n;
        }
    }    

    func(0);

    cout << min_stage << endl;
    for (int i = 0; i < min_stage; i++) {
        cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << endl;
    }

    return 0;
}