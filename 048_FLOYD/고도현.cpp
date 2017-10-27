#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> money(101, vector<int>(101, 0));
vector<vector<int>> dist(101, vector<int>(101, 200000));

void FloydWarshall(int N);
int main(void) {
	int N = 0, M = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int s = 0, e = 0, m = 0;
		scanf("%d %d %d\n", &s, &e, &m);
		if(money[s][e]>m || money[s][e]==0) money[s][e] = m;
	}

	FloydWarshall(N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dist[i][j] << " ";
		}
		puts("");
	}
	return 0;
}

void FloydWarshall(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(money[i][j]!=0)	dist[i][j] = money[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++) dist[i][i] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}
}