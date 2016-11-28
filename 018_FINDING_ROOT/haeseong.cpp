/********************************************
	27 Nov. 2016
	Haeseong Jeon

	11403. 경로찾기. 
	https://www.acmicpc.net/problem/11403
*********************************************/

#include <cstdio>

int N;			// 1 <= N <= 100
int d[101][101];

int main()
{
	scanf("%d", &N);
	
	int i, j, k;
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			scanf("%d", &d[i][j]);

	for(k=1; k<=N; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				if(d[i][k] && d[k][j])
					d[i][j] = 1;

	for(i=1; i<=N; i++) {
		for(j=1; j<=N; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}

	return 0;
}

