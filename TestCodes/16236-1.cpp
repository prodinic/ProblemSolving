#include <stdio.h>
#include <memory.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct pos {
	int x;
	int y;
};
struct item {
	pos p;
	int time;
};
int map[22][22];
int main() {
	int n;
	int ss = 2;
	pos sp;
	memset(map, -1, 22 * 22 * sizeof(int));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				sp.x = j;
				sp.y = i;
				map[i][j] = 0;
			}
		}
	}
	int second = 0, success = 1, eat_count = 0;
	while (success) {
		success = 0;
		item p[401] = { 0 };
		int visit[22][22] = { 0 };
		int fnt = 0, bck = 0;
		int max_time = INF;
		p[bck++] = { sp, 0 };
		while (bck > fnt) {
			item cur = p[fnt++];
			int cur_time = cur.time;
			if (success == 1 && cur.time >= max_time) continue;
			for (int i = 0; i < 4; i++) {
				int x = dx[i] + cur.p.x;
				int y = dy[i] + cur.p.y;
				if (visit[y][x] != 1) {
					visit[y][x] = 1;
					int next_state = map[y][x];
					if (next_state == 0 || ss == next_state) {
						p[bck++] = { { x,y }, cur_time + 1 };
					}
					else if (next_state > 0 && next_state < ss) {
						if (success) {
							if (sp.y > y) {
								sp.x = x;
								sp.y = y;
							}
							else if (sp.y == y && sp.x > x) {
								sp.x = x;
								sp.y = y;
							}
						}
						else {
							success = 1;
							max_time = cur_time + 1;
							sp.x = x;
							sp.y = y;
						}
					}
				}
			}
		}
		if (success) {
			eat_count++;
			map[sp.y][sp.x] = 0;
			if (eat_count == ss) {
				ss++;
				eat_count = 0;
			}
			second += max_time;
		}
	}
	printf("%d\n", second);
}