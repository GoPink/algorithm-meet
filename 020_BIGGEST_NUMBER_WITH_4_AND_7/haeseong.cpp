/*
    12 Nov. 2016
    Haeseong Jeon
 
	1526. 금민수.
    https://www.acmicpc.net/problem/1526
*/

#include <cstdio>
using namespace std;

int N;		// 4 <= N <= 1000000

bool isGMS(int a)
{
	for( ; a>0; a/=10) {	
		if(a%10==4)
			continue;
		else if(a%10==7)
			continue;
		else
			return false;
	}
	return true;
}

int main()
{
	scanf("%d", &N);
	
	int max = 0;
	for(int i=4; i<=N; i++)
		if(isGMS(i) && max<i)
			max = i;

	printf("%d\n", max);

	return 0;
}
