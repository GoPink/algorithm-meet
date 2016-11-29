/********************************************
	29 Nov. 2016
	Haeseong Jeon

   	10815. 숫자 카드
	https://www.acmicpc.net/problem/10815
********************************************/
#include <cstdio>
#include <vector>		// std::vector
#include <algorithm>	// std::sort
using namespace std;

int N, M;
vector<int> v;

int main()
{
    int a;
	
    scanf("%d", &N);
	while(N-->0) {
		scanf("%d", &a);
		v.push_back(a);
	}
    
	sort(v.begin(), v.end());

	scanf("%d", &M);
	while(M-->0) {
		scanf("%d", &a);
		printf("%d ", binary_search(v.begin(), v.end(), a));
	}
	printf("\n");

	return 0;
}
