#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

vector<pair<int, int>> adj[20001];
priority_queue<pair<int, int>> q;
int d[20001];

void Dijkstra(int start, int V);
int main(void) {
	int V = 0, E = 0, start = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%d %d\n", &V, &E);
	scanf("%d\n", &start);
	for (int i = 1; i <= E; i++) {
		int s = 0, e = 0, w = 0;
		scanf("%d %d %d\n", &s, &e, &w);
		adj[s].push_back(make_pair(e, w));
	}
	Dijkstra(start, V);
	for (int i = 1; i <= V; i++) {
		if (d[i] == INT32_MAX) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
	return 0;
}

void Dijkstra(int start, int V) {
	for (int i = 1; i <= V; i++) d[i] = INT32_MAX;
	d[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		int current_weight = -q.top().first;
		int current_position = q.top().second;
		q.pop();
		if (d[current_position] < current_weight) continue;
		for (int i = 0; i < adj[current_position].size(); i++) {
			int next_weight = adj[current_position][i].second;
			int next_position = adj[current_position][i].first;

			if (d[next_position] > next_weight+d[current_position]) {
				d[next_position] = d[current_position] + next_weight;
				q.push(make_pair(-next_weight, next_position));
			}
		}
	}
}