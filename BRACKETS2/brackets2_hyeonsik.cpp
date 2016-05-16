#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n;
void brackets2(const string& input){
	const string openning = "[{(", clossing = "]})";
	stack<char> st;
	for(int i = 0; i<input.length(); i++){
		//���� ���ڰ� ���� ��ȣ�� ���ÿ� ���� 
		if(openning.find(input[i]) != string::npos)
			st.push(input[i]);
		else {
			if(!st.empty()&&openning.find(st.top()) == clossing.find(input[i]))
				st.pop();
			else{
				printf("NO\n");
				return;
			} 
		}
	}
	//���ڸ� �� �˻����� �� ������ ������� YES, �ƴϸ� NO 
	if(st.empty()) printf("YES\n");
	else printf("NO\n");
	
}
int main(){
	scanf("%d",&n);
	while(n--){
		string input;
		cin>>input;
		brackets2(input);
	}
}
