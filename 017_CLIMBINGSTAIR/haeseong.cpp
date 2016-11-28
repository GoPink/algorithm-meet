/*
	29 Nov. 2016
	Haeseong Jeon

	2579. øø øøø
	https://www.acmicpc.net/problem/2579
*/

#include <cstdio>
#include <algorithm>	// std::max
using namespace std;

short int N;			// N <= 300
short int stair[300];	// stair[i] <= 10000
int d[300][2];

int main()
{
	scanf("%hd", &N);
	for (int i=0; i<N; i++)
		scanf("%hd", &stair[i]);

	d[0][0] = stair[0];
	d[0][1] = stair[0];
	d[1][0] = stair[1]+stair[0];
	d[1][1] = stair[1];
	d[2][0] = stair[2]+stair[1];
	d[2][1] = stair[2]+stair[0];
	
	for (int i=3; i<N; i++) {
        // 1계단 전
		d[i][0] = stair[i] + d[i-1][1];
        // 2계단 전
		d[i][1] = stair[i] + max(d[i-2][0], d[i-2][1]);
	}

	printf("%d\n", max(d[N-1][0], d[N-1][1]));

	return 0;
}
