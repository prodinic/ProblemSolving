// 로봇 청소기
// 5:50

#include <iostream>

using namespace std;

int n, m, t = 0;
int arr[51][51];
bool visited[51][51] = { false };

class Point {
public:
   int y, x;
};
Point p[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void printAll() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int y, x, d, ny, nx, nd, rotate;
   bool flag = true;
   cin >> n >> m;
   cin >> y >> x >> d;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         cin >> arr[i][j];


   while (flag) {
      if (!arr[y][x]) {
          visited[y][x] = true;
         arr[y][x] = 2;
         t++;
      }

      // (0 > 3 > 2 >> 1 >> 0)
      for (int i = 0; i < 4; i++) {
         d = (d + 3) % 4;
         ny = y + p[d].y;
         nx = x + p[d].x;
         if(!arr[ny][nx]){
            y = ny;
            x = nx;
            break;
         }

         if (i != 3 && arr[ny][nx] == 1) {
             continue;
         }
      // (0 > 2) (1 > 3)
         if (i == 3) {


            //  printAll();
            // cout << "ny : "<< ny << " | nx : " << nx << "nd : " << nd <<  endl;
            nd = (d + 2) % 4;
            y += p[nd].y;
            x += p[nd].x;
            if (arr[y][x] == 1) 
            flag = false;
            break;
        
         }
      }
   }
   cout << t << '\n';
   return 0;
}