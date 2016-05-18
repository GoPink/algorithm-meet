#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <stack>
using namespace std;
string input;
int matching[221], brkNum = 0; 
bool erasing[221]; 
set<string> retSet;
string ret;

//���ڿ��� ������.
// ������ ����� ��
// 1. ���� ���ڰ� ��ȣ�ϰ�� : (1) �����, (2) �������
// 2. ���� ���ڰ� ��ȣ�� �ƴ� ��� : ���ڿ��� ��� �����. 

//void eraseBrackets(int cur){
//	//������� : ���ڿ��� �ϼ�
//	if(cur == input.length()){
//		retSet.insert(ret);
//		return;
//	} 
//
//	if(input[cur] == '('){	
//		//����� ���
//		erasing[matching[cur]] = true;
//		eraseBrackets(cur+1);	
//		erasing[matching[cur]] = false;
//	
//		//������� ���
//		ret+=input[cur];
//		eraseBrackets(cur+1);
//		ret.erase(ret.begin()+cur-1);
//	
//	}
//	else if(input[cur] ==')'){
//		//¦��ȣ�� ���� ��� 
//		if(erasing[cur]) eraseBrackets(cur+1);
//		//������ ��� 
//		else {
//			ret+=input[cur];
//			eraseBrackets(cur+1);
//			ret.erase(ret.begin()+cur-1);
//		}
//	}
//	else{
//		ret+=input[cur];
//		eraseBrackets(cur+1);
//		ret.erase(ret.begin()+cur-1);
//	}
//}

void eraseBrackets(int cur){
	//������� : ���ڿ��� �ϼ�
	if(cur == input.length()){
		retSet.insert(ret);
		return;
	} 
	if(input[cur] == '('){	
		//��ȣ�� ����� ���
		erasing[matching[cur]] = true;
		eraseBrackets(cur+1);	
		erasing[matching[cur]] = false;
	}
	if(input[cur] ==')'&&erasing[cur]){
		//¦��ȣ�� ���� ��� 
		eraseBrackets(cur+1);
	}
	//��ȣ,¦��ȣ�� ������ų� �Ϲ� ���ڿ��� ���. 
	else{
		ret+=input[cur];
		eraseBrackets(cur+1);
		ret.resize(ret.size()-1);
		//ret.erase(ret.begin()+cur-1);
	}
}


//��ȣ ��Ī ���� 
void matchBrackets(string& input){
	stack<int> st;
	for(int i = 0; i<input.length();i++){
		if(input[i] == '(') st.push(i);
		else if(input[i] == ')'){
			//��Ī�� �Ǵ� ��ȣ�� �����Ѵ�. 
			matching[i] = st.top();
			matching[st.top()] = i;		
			st.pop();
			brkNum++;
		}
	}
}
int main(){
	cin>>input;
	matchBrackets(input);
	eraseBrackets(0);
	retSet.erase(input);
	set<string>::iterator it;
	for(it = retSet.begin(); it!=retSet.end(); it++)
		cout<<(*it)<<endl;
}
