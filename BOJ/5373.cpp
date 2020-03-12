#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define U 1
#define D 4
#define B 2
#define F 16
#define R 8
#define L 32
#define ROTATE_AROUND_U 58
#define ROTATE_AROUND_D 58
#define ROTATE_AROUND_B 45
#define ROTATE_AROUND_F 45
#define ROTATE_AROUND_R 23
#define ROTATE_AROUND_L 23

int rotate_around_u_clockwise[] = {2, 8, 16, 32};
int rotate_around_d_clockwise[] = {};
int rotate_around_b_clockwise[] = {1, 32, 4, 8};
int rotate_around_f_clockwise[] = {};
int rotate_around_r_clockwise[] = {1, 2, 4, 16};
int rotate_around_l_clockwise[] = {};

using namespace std;

char dice[64][9];

void initDice() {

    for (int i = 1; i < 64; i = i << 1) {

        if (i == U) {

            for (int j = 0; j < 9; j++) {
                dice[U][j] = 'w';
            }
        }
        else if (i == D) {

            for (int j = 0; j < 9; j++) {
                dice[D][j] = 'y';
            }

        }
        else if (i == F) {

            for (int j = 0; j < 9; j++) {
                dice[F][j] = 'r';
            }
            
        }
        else if (i == B) {

            for (int j = 0; j < 9; j++) {
                dice[B][j] = 'o';
            }
            
        }
        else if (i == L) {

            for (int j = 0; j < 9; j++) {
                dice[L][j] = 'g';
            }
            
        }
        else if (i == R) {

            for (int j = 0; j < 9; j++) {
                dice[R][j] = 'b';
            }
            
        }
    }


}

int main() {

    int T, num;
    cin >> T;
    initDice();

    while(T--) {

        cin >> num;
        while (num--) {

            string s;
            cin >> s;

            if (s.at(0) == 'U') {
                if (s.at(1) == '-') {

                }
                else {
                    int tmp[3];
                    for (int i = 0; i < 4; i++) {
                        int x = rotate_around_u_clockwise[i];
                        
                    }
                }
            }
            else if (s.at(0) == 'D') {
                if (s.at(1) == '-') {

                }
                else {
                    
                }
            }
            else if (s.at(0) == 'B') {
                if (s.at(1) == '-') {

                }
                else {
                    
                }                
            }
            else if (s.at(0) == 'F') {
                if (s.at(1) == '-') {

                }
                else {
                    
                }                
            }
            else if (s.at(0) == 'R') {
                if (s.at(1) == '-') {

                }
                else {
                    
                }                
            }
            else if (s.at(0) == 'L') {
                if (s.at(1) == '-') {

                }
                else {
                    
                }                
            }
            else {
                break;
            }
        }
    }



    return 0;
}