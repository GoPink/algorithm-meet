#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int paper[100][100] = { 0, };

int di[4][2] = {
	{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 },
	{ -1, 0 }
};

/**
 *	if there is no cheese, return true
 *	O(N*M)
 */
bool isEnd()
{
	int count = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			count += paper[i][j];
		}
	}
	return count == 0 ? true : false;
}

/**
 *	Replace 0 to 10 if air is outside
 */
void checkAir()
{
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	paper[0][0] = 10;

	int a, b, c, d;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		// printf("(%d,%d)\n", a, b);
		q.pop();

		for (int i = 0; i < 4; i++) {
			c = a + di[i][0];
			d = b + di[i][1];
			if(c<0 || c==N || d<0 || d==M)
				continue;
			if (paper[c][d] == 0) {
				q.push(make_pair(c, d));
				// printf("(%d,%d)\n", c, d);
				paper[c][d] = 10;
			}
		}
	}
}

/**
 *	Restore 10 to 0
 *  O(N*M)
 */
void restore() {
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			paper[i][j] %= 10;
}

/**
 *	print 
 *	O(N*M)
 */
void print()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%2d", paper[i][j]);
		printf("\n");
	}
}

/**
 *	main
 */
int main()
{
	freopen("input_03.txt", "r", stdin);

	int i, j, k, time = 0;
	queue<pair<int, int> > q;

	// input
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	while (true) {
		int a, b, count; 

		// set 0 (i,j) in queue
		while (!q.empty()) {
			i = q.front().first;
			j = q.front().second;
			q.pop();
			paper[i][j] = 0;
		}

		// find
		checkAir();
		//print();
		
		// count
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < M - 1; j++) {
				if (paper[i][j] == 1) {
					count = 0;
					for (k = 0; k < 4; k++) {
						a = di[k][0];
						b = di[k][1];
						if(paper[i+a][j+b]==10)
							count+=1;
					}
					if (count >= 2) {
						q.push(make_pair(i, j));
						//printf("(%d,%d)\n", i, j);
					}
				}
			}
		}
		restore();

		if (q.empty())
			break;
		else
			time += 1;
	} 

	//print();
	printf("hour:%d\n", time);

	return 0;
}
