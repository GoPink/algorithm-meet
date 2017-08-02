#include<cstdio>
using namespace std;

int main()
{
	int N;
	int v[100001] = {0,};
	long long sum = 0;
	long long int answer = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &v[i]);
		sum += v[i];
	}

	for(int i=0; i<N; i++) {
		answer += v[i] * (sum - v[i]);
	}
	printf("%lld\n", answer/2);

	return 0;
}

