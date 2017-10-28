#include<cstdio>
#include<algorithm>
using namespace std;

#define		MAX		100000
int N;	// 1<= N <= 100
int M;	// 1<= M <= 100000
int w[101][101];
int d[101][101];

int main()
{
	int i, j, k;
	scanf("%d %d", &N, &M);

	for(i=1; i<=N; i++) {
		for(j=1; j<=N; j++) {
			w[i][j] = -1;		
			d[i][j] = MAX;
		}
	}

	while(M-->0) {
		scanf("%d %d %d", &i, &j, &k);
		if(w[i][j]==-1)
			d[i][j] = w[i][j] = k;	
		else if(k < w[i][j]) 
			d[i][j] = w[i][j] = k;
	}

	for(k=1; k<=N; k++) 
		for(i=1; i<=N; i++) 
			for(j=1; j<=N; j++) 
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

	for(i=1; i<=N; i++) {
		for(j=1; j<=N; j++) {
			if(i==j) 
				printf("0 ");
			else if(d[i][j] == MAX)
				printf("0 ");
			else
				printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	return 0;
}
