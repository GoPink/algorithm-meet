#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[501];
vector<int> d(501, INT32_MAX);
int visit[501];
bool result = false;

bool BellmanFord(int start, int vertex, bool &result);
int main(void) {
	int N = 0, M = 0, wornhole = 0, Test = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &Test);
	while (Test--) {
		scanf("%d %d %d\n", &N, &M, &wornhole);
		for (int i = 1; i <= M; i++) {
			int s = 0, e = 0, w = 0;
			scanf("%d %d %d\n", &s, &e, &w);
			adj[s].push_back(make_pair(e, w));
			adj[e].push_back(make_pair(s, w));
		}
		for (int i = 1; i <= wornhole; i++) {
			int s = 0, e = 0, w = 0;
			scanf("%d %d %d\n", &s, &e, &w);
			adj[s].push_back(make_pair(e, -w));
		}

		if (BellmanFord(1, N, result)) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		for (int i = 1; i <= N; i++) {
			d[i] = INT32_MAX;
			adj[i].clear();
			visit[i] = 0;
			result = false;
		}
	}
}

bool BellmanFord(int start, int vertex, bool &result) {
	d[start] = 0;
	visit[start] = 1;
	for (int i = 1; i <= vertex; i++) {
		for (int j = 1; j <= vertex; j++) {
			for (auto it = adj[j].begin(); it != adj[j].end(); it++) {
				if (d[j] != INT32_MAX && d[it->first] > d[j] + it->second) {
					d[it->first] = d[j] + it->second;
					visit[it->first] = 1;
					if (i == vertex) result = true;
				}

			}
		}
	}
	int next = 0;
	for (int i = 1; i <= vertex; i++) {
		if (visit[i] == 0) BellmanFord(i, vertex, result);
	}
	return result;
}