#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	char str[100001] = { 0, };
	scanf("%s", str);

	stack<char> s;
	int sum = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '(' && str[i + 1] == ')') {
			sum += s.size();
			i += 1;
		}
		else if (str[i] == '(') {
			s.push('(');
		}
		else {
			if(!s.empty())
				s.pop();
			sum += 1;
		}
	}
	printf("%d\n", sum);

	return 0;
}