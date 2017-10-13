#include <iostream>
#include <string>
using namespace std;

string str[50];
int main(void) {
	int N = 0;
	string result;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
		getline(cin, str[i]);
	result.assign(str[0]);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < str[0].size(); j++) {
			if (str[0][j] != str[i][j]) {
				result.replace(j, 1, "?");
			}
		}
	}
	cout << result;
	return 0;
}