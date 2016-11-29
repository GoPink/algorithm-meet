/**********************************************
	29 Nov. 2016
	Haeseong Jeon

	11501. 주식
	https://www.acmicpc.net/problem/11501	
**********************************************/
#include <cstdio>

int T, N;
int s[1000000];
long long int profit = 0;

void getProfit(int begin, int end) {
	if(begin>end)
		return;

	int max = begin;
	for(int i=begin; i<=end; i++)
		if(s[max]<s[i])
			max = i;

	// [begin,max)
	for(int i=begin; i<max; i++)
		profit += s[max] - s[i];

	// (max, end]
	getProfit(max+1, end);
}

int main()
{
	scanf("%d", &T);
	while(T-->0) {
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &s[i]);
	
		profit = 0;
		getProfit(0, N-1);
		printf("%lld\n", profit);
	}
	return 0;
}

