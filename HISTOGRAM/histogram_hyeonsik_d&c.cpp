#include <cstdio>
#include <algorithm>
using namespace std;
int n, height[100000];


int histogram(int left, int right){
	//������� : ��ĭ�� ������ ���. 
	if(left == right) return height[left];
	int mid = (left+right)/2, ret;
	//mid�� ������ ��,���� histogram �ִ밪�� ���Ѵ�. 
	ret =  max(histogram(left,mid),histogram(mid+1,right));
	//mid�� �߰��� ��ģ histogram�� ���Ѵ�. 
	int rr = mid+1, ll = mid, curHeight=min(height[rr],height[ll]);
	ret = max(ret, curHeight*2);
	
	//height�� ū ������ �ϳ��� �¿츦 Ȯ���ذ��� ���Ѵ�. 
	while(ll>left || rr<right){ 
		if(rr<right && (ll == left ||height[rr+1]>height[ll-1])){
			rr++;	
			curHeight = min(curHeight,height[rr]);
		} else {
			ll--;
			curHeight = min(curHeight,height[ll]);
		}
		ret = max(ret, curHeight*(rr-ll+1));
	}
	return ret;	 
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&height[i]);
	printf("%d",histogram(0,n-1));
}
