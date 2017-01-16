#include <iostream>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// ���� : http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220574993422
 
const int row_cord[4] = {-1,1,0,0};
const int col_cord[4] = {0,0,-1,1};
int main(int argc, char** argv) {
	
	//INPUT
	int N,M;
	scanf("%d %d",&N,&M);
	bool map[100][100];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d",&map[i][j]);
			
	bool visited[100][100] = {0}; // *1: innitialize as 0 
	visited[0][0] = true;
	
	//*2: ť-�� ���¸� "��*100+��"�� �ؽð����� ���   
	queue<int> Q;
	Q.push(0);
	
	//�̵�Ƚ��
	int result = 1;
	
	/*
	���� while���� queue�� ���� �ʾƾ� ���� �� ������
	�� ���� �׻� ���� ������ ��츸 �־���  
	*/ 
	while(1){
		int qSize = Q.size();
		//*4 : �̰ɷ� result, �ܰ踦 ����  
		for(int i=0; i<qSize; i++){
			int r = Q.front()/100; 
			int c = Q.front()%100;	
			Q.pop();
			
			//������ ���
			if(r==N-1 && c==M-1){
				printf("%d\n",result);
				return 0;
			} 
			
			//*3: 4������ �����ϴ� ���� �ƴ϶� _cord�迭 �̿�!  
			for( int d=0; d<4; d++){
				
				//4���� Ž�� 
				int nr = r + row_cord[d];
				int nc = c + col_cord[d];
				
				//�̷� �ٱ� ���� 
				if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
				
				//���� ��� ����
				if(!map[nr][nc]) continue;
				
				//�湮�� ��ġ��� �н� 
				if(visited[nr][nc]) continue;
				  
				//�� ��찡 �ƴ϶�� �湮 ǥ�� + ť�� �߰�
				visited[nr][nc] = true;
				Q.push(nr*100+nc); 
			} 
		}
		//*4 : result�� �ܰ踦 ǥ�� 
		result++; 
	}
	
	
	return 0;
}
