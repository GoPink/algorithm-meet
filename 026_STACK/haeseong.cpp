#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
	int N;			// 1 <= N <= 10000
	string str;
	int X;
	stack<int> s;

	cin >> N;
	getchar();

	while (N-- > 0) {
		getline(cin, str);

		switch (str[0]) {
		// push, pop
		case 'p':
			// push
			if (str[1] == 'u') {
				stringstream ss(str);
				string token;
				ss >> token;	// push
				ss >> token;	// X
				X = stoi(token);

				s.push(X);
			}
			// pop
			else {
				if (s.empty())
					cout << "-1" << endl;
				else {
					cout << s.top() << endl;
					s.pop();
				}
			}
			break;
		// size
		case 's':	
			cout << s.size() << endl;
			break;
		// empty
		case 'e':
			if (s.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
			break;
		// top
		case 't':
			if (s.empty())
				cout << "-1" << endl;
			else
				cout << s.top() << endl;
			break; 
		}
	}

	return 0;
}