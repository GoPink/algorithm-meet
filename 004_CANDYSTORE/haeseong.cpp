/**********************************************
	23 Nov. 2016
	Haeseong Jeon

	4781. Candy Store
	https://www.acmicpc.net/problem/4781

**********************************************/
#include <algorithm>	// std::max
#include <utility>		// std::pair, make_pair
#include <vector>		// std::vector
#include <cstdio>		// scanf, printf
using namespace std;

int n;		// 1 <= n <= 5000
double m;	// 0.01 <= m <= 100.00
int d[10001] = {0,};
vector<pair<int, int> > v;

int main()
{
	//freopen("input_4781.txt", "r", stdin);

	scanf("%d %lf", &n, &m);
	int money = 100 * m;
	int c;
	double p;
	pair<int, int> myPair;
	while(!(n==0 && m==0.00)) {
		v.clear();

		// input candies (calory, price)
		for(int i=0; i<n; i++) {
			scanf("%d %lf", &c, &p);
			myPair = make_pair(c, (int)100*p);
			v.push_back(myPair);
		}
		
		// calculate d[i]
		d[0] = 0;
		int candidate = 0;
		for(int i=1; i<=money; i++) {
			d[i] = d[i-1];
			for(auto iter = v.begin(); iter!=v.end(); ++iter) 
				if(i >= iter->second)
					d[i] = max(d[i], d[i-iter->second] + iter->first);
		}

		// print a answer
		printf("%d\n", d[money]);
		
		// new input 
		scanf("%d %lf", &n, &m);
		money = 100*m;
	}

	return 0;
}
