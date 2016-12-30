#include <cstdio>
#include <stack>		// std::stack
using namespace std;

bool isVPS(char* str) {
	stack<char> s;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty())
				return false;
			else
				s.pop();
		}
	}

	if (s.empty())
		return true;
	else
		return false;
}

int main()
{
	int T;
	char str[51];
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%s", str);
		if (isVPS(str))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}