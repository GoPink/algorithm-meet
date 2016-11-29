/**********************************************
  	30 Nov. 2016
	Haeseong Jeon

	2800. 괄호 제거
	https://www.acmicpc.net/problem/2800
**********************************************/
#include <iostream>		// std::cin, cout, endl
#include <stack>		// std::stack
#include <string>		// std::string
#include <vector>		// std::vector
#include <algorithm>	// std::sort, unique
#include <cmath>		// std::pow
using namespace std;

stack<int> s;
int b[10][2];		// 1 <= brackets <= 10, [0] : open, [1] : close.
vector<string> v;
string str;

int main()
{
	getline(cin, str);	

    // find set of brackets
	int i, j;
	for(i=0, j=0; i<str.length(); i++) {
		if(str.at(i) == '(') {
			s.push(i);
		}
		else if(str.at(i) == ')') {
			b[j][0] = s.top();
			b[j][1] = i;
			s.pop();
			j += 1;
		}
		else {
			continue;
		}
	}

    // 괄호 쌍을, 모든 경우에 대해 하나씩 지움. (순열.. )
	int m = j;
    
	for(i=1; i<=pow(2,m)-1; i++) {
		string temp = str;

        // 지워야 할 괄호쌍을 빈칸으로 치환.
		for(j=0; j<m; j++) {	
			if((i>>j)%2==1) {
				temp.at(b[j][0]) = ' ';
				temp.at(b[j][1]) = ' ';
			}

		}
        
        // 빈칸을 모두 찾아서 지움.
		auto end_pos = remove(temp.begin(), temp.end(), ' ');
		temp.erase(end_pos, temp.end());

        // 정답 후보 목록에 추가.
		v.push_back(temp);
	}

    // sort
	sort(v.begin(), v.end());	

	// unique
    // 중복되는 부분 문자열 삭제.
	auto end_pos = unique(v.begin(), v.end());
	v.erase(end_pos, v.end());

    // print answer
	for(auto iter = v.begin(); iter!=v.end(); ++iter)
		cout << *iter << '\n';

	return 0;
}
