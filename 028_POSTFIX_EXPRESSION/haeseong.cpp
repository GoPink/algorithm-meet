#include <iostream>
#include <string>	// std::string
#include <stack>	// std::stack
using namespace std;

int order(char c) {
	switch(c) {
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	stack<char> s;
	string str;
	string answer = "";
	cin >> str;

	for(auto it = str.begin(); it!=str.end(); ++it) {
		if(*it <= 'Z' && *it >= 'A') {
			answer += *it;
		}
		else if(*it == '(') {
			s.push(*it);
		}
		else if(*it == ')') {
			while(s.top()!='(') {
				answer += s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			while(!s.empty() && order(s.top()) >= order(*it)) {
				answer += s.top();
				s.pop();
			}
			s.push(*it);
		}
	}

	while(!s.empty()) {
		answer += s.top();
		s.pop();
	}

	cout << answer << '\n';

	return 0;
}
