#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#define MAX_V 22222
#define INF 1111111

using namespace std;
//the number of verge
int V,E,K;

//the adjacency list for graph
vector<pair<int, int> > adj[MAX_V];
vector<int> dist(MAX_V, INF);

void dijkstra(int src) {

	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		//만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
		if (dist[here] < cost) continue;

		//인접한 정점들을 모두 검사한다.
		for (unsigned int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			
			//더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
}
int main() {

    int x, y, cost;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

	for (int i = 0; i < E; i++) {

        scanf("%d %d %d", &x, &y, &cost);
		adj[x].push_back(make_pair(y,cost));
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++)
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);

	return 0;

}