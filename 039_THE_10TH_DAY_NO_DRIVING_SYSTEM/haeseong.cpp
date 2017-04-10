#include <cstdio>
int main()
{
	int N, M;
	int ans = 0;
	scanf("%d", &N);

	for(int i=0; i<5; i++) {
		scanf("%d", &M);
		if(N==M)
			ans += 1;
	}
	printf("%d\n", ans);

	return 0;
}
