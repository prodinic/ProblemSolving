#include <stdio.h>
#include <string.h>
#define MAX_LEN 1<<8

int map[MAX_LEN][MAX_LEN];
int K;
int structure_number = 1;
int x, y;

void init() {
    memset(map, 0, sizeof(map));
    map[(1<<K) - x][-1 + y] = -1;
}

void tiling(int from_x, int to_x, int from_y, int to_y) {

    int len = to_x - from_x + 1;
    if (len == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (map[from_x + i][from_y + j] == -1 || map[from_x + i][from_y + j] > 0) continue; // hole or already tiled
                map[from_x + i][from_y + j] = structure_number;
            }
        }
        structure_number++; 
    }
    else if (len == 4) {
        if (from_x + 1 <= x && x <= to_x - 1 && from_y + 1 <= y && y <= to_y - 1) {
            tiling(from_x + 1, to_x - 1, from_y + 1, from_y - 1);   // center
        }
        else {
            for (int i = 0; i < 4; i++) {
                int next_from_x = 
            }
        }
    }
    else {


    }

}
void solve() {

    init();


}
int main() {

    int K;
    scanf("%d", &K);
    scanf("%d %d", &x, &y);





    return 0;
}