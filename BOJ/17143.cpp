#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX_LEN 101
#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 3

using namespace std;

struct shark {
    int x, y; 
    int speed;
    int dir;
};

struct info {
    bool visited;
    int speed;
    int weight;
    int dir;
};

int R, C, M;
info map[MAX_LEN][MAX_LEN];
vector<pair<int, shark> > v; 


bool compare(pair<int, shark> a, pair<int, shark> b) {

    if (a.first < b.first) return false;
    else return true;
}

void printAll() {

    for (int i = 0; i < v.size(); i++) {

        cout << "weight : "<<v[i].first<< " | x : "<<v[i].second.x << " | y : "<<v[i].second.y << " | speed : "<<v[i].second.speed << " | dir : " << v[i].second.dir << endl;
    }
}
void move() {

    for (int i = 0; i < v.size(); i++) {
        int speed = v[i].second.speed;
        int dir = v[i].second.dir;
        int x = v[i].second.x;
        int y = v[i].second.y;

        if (dir == UP) {
            if (speed / (2 * (R - 1)) > 0) {
                speed -= (speed / (2 * (R - 1))) * 2 * (R - 1); 
            } 
            if (x - speed > 1) {
                x -= speed;

            }
            else if (x + 2 * (R - 1) - speed <= R) {
                x += 2 * (R - 1) - speed;

            }
            else {
                x = speed - x + 2;
                dir = DOWN;
            }
        }
        else if (dir == DOWN) {
            if (speed / (2 * (R - 1)) > 0) {
                speed -= (speed / (2 * (R - 1))) * 2 * (R - 1); 
            }
            if (x + speed < R) {    // same way

                x += speed;
            }   
            else if (R <= x + speed && x + speed < 2 * R - 1) { // opposite way
                
                x = R - (x + speed) % R;
                dir = UP;
            }     
            else {  // same way

                x -= 2 * (R - 1) - speed;
            }
        }
        else if (dir == LEFT) {
            if (speed / (2 * (C - 1)) > 0) {
                speed -= (speed / (2 * (C - 1))) * 2 * (C - 1); 
            }
            if (y - speed > 1) {
                y -= speed;

            }
            else if (y + 2 * (C - 1) - speed <= C) {
                y += 2 * (C - 1) - speed;

            }
            else {
                y = speed - y + 2;
                dir = RIGHT;
            }
        }
        else if (dir == RIGHT) {
            if (speed / (2 * (C - 1)) > 0) {
                speed -= (speed / (2 * (C - 1))) * 2 * (C - 1); 
            }
            if (y + speed < C) {
                y += speed;
            }
            else if (C <= y + speed && y + speed < 2 * C - 1) {

                y = C - (y + speed) % C;
                dir = LEFT;
            }
            else {
                y -= 2 * (C - 1) - speed;
            }
        }

        v[i].second.dir = dir;
        v[i].second.x = x;
        v[i].second.y = y;
    }    
}

int main() {

    int answer = 0;
    int r, c, s, d, z;
    shark sh;

    cin >> R >> C >> M;

    // input
    for (int i = 0; i < M; i++) {

        cin >> r >> c >> s >> d >> z;
        shark ss2;
        ss2.dir = d;
        ss2.speed = s;
        ss2.x = r;
        ss2.y = c;

        map[r][c].dir = d;
        map[r][c].speed = s;
        map[r][c].weight = z;
        map[r][c].visited = true;
        v.push_back(make_pair(map[r][c].weight, ss2));
    }

    for (int pos = 1; pos <= C; pos++) {

        // find closest shark    
        for (int j = 1; j <= R; j++) {
            if (map[j][pos].visited == true) {
                
                for (int k = 0; k < v.size(); k++) {
                    if (v[k].second.x == j && v[k].second.y == pos) {
                        v.erase(v.begin() + k);
                        break; 
                    }
                }
                answer += map[j][pos].weight;
                map[j][pos].visited = false;    
                break;
            }
        }

        // sharks move their own way
        // cout << "before moving" << endl;
        // printAll();
        move();
        // cout << "after moving" << endl;
        // printAll();

        // sort by weight
        // cout << "before sorting" << endl;
        // printAll();
        sort(v.begin(), v.end(), compare);
        // cout << "after sorting" << endl;
        // printAll();

        // init
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                
                map[i][j].visited = false;
            }
        }       

        // locate each shark on specific position
        for (int i = 0; i < v.size(); i++) {
            
            if (map[v[i].second.x][v[i].second.y].visited == true) {
                continue;
            }
            else {
                map[v[i].second.x][v[i].second.y].visited = true;
                map[v[i].second.x][v[i].second.y].weight = v[i].first;
                map[v[i].second.x][v[i].second.y].dir = v[i].second.dir;
                map[v[i].second.x][v[i].second.y].speed = v[i].second.speed;
            }
        }

        // clear vector v 
        v.clear();

        // collect survived sharks
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                
                if (map[i][j].visited == true) {
                    shark ss;
                    ss.dir = map[i][j].dir;
                    ss.speed = map[i][j].speed;
                    ss.x = i;
                    ss.y = j;

                    v.push_back(make_pair(map[i][j].weight, ss));
                }
            }
        }



    }

    cout << answer << endl;

    return 0;
}