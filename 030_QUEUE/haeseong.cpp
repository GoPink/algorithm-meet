#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

int main()
{
	int N;
	string str;
	int X;
	queue<int> q;

	cin >> N;
	getchar();	// '\n'

	while(N-->0) {
		getline(cin, str);

		switch(str[0]) {
		// push, pop
		case 'p':
			if(str[1]=='u') {
				stringstream ss(str);
				string token;
				ss >> token;	// push
				ss >> token;	// X
				X = stoi(token);

				q.push(X);
			}
			else {
				if(q.empty())
					cout << "-1" << '\n';
				else {
					cout << q.front() << '\n';
					q.pop();
				}
			}
			break;
		// size
		case 's':
			cout << q.size() << '\n';
			break;
		// empty
		case 'e':
			if(q.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
			break;
		// front
		case 'f':
			if(q.empty())
				cout << "-1" << '\n';
			else
				cout << q.front() << '\n';
			break;
		// back
		case 'b':
			if(q.empty())
				cout << "-1" << '\n';
			else
				cout << q.back() << '\n';

			break;
		}
	}

	return 0;
}
