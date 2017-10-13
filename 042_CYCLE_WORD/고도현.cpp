#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string str[50];
int d[50];

int main(void) {
	int N = 0, result = 0;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
		getline(cin, str[i]);
	for (int i = 0; i < N; i++) {
		if (d[i] == 1) continue;
		else {
			result++;
			for (int j = i + 1; j < N; j++) {
				string tmp = str[j];
				if (tmp.size() != str[i].size()) continue;
				for (int k = 0; k < str[j].size(); k++) {
					rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
					if (tmp == str[i]) {
						d[j] = 1;
						break;
					}
				}
			}
		}
	}
	cout << result;
	return 0;
}