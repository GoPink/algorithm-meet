/*********************************************
    25 Oct. 2016
    Haeseong Jeon

    9465. Sticker
    https://www.acmicpc.net/problem/9465
 
*********************************************/
 
#include <iostream>
#include <algorithm>    // std::max
using namespace std;

int main()
{
    int T;
	int N;	// 1 <= n <= 100,000

	int s[100001][2];
	int d[2][3] = { 0 };
	
	cin >> T;

	while (T-- > 0) {
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> s[i][0];
		for (int i = 1; i <= N; i++)
			cin >> s[i][1];

		d[0][0] = s[1][0];
		d[0][1] = s[1][1];
		d[0][2] = 0;

		for (int i = 2; i <= N; i++) {
			d[1][0] = s[i][0] + max(d[0][1], d[0][2]);
			d[1][1] = s[i][1] + max(d[0][0], d[0][2]);
			d[1][2] = max(d[0][0], d[0][1]);

			d[0][0] = d[1][0];
			d[0][1] = d[1][1];
			d[0][2] = d[1][2];
		}

		cout << max(d[0][0], max(d[0][1], d[0][2])) << endl;
	}

	return 0;
}
