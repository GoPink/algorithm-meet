#include <iostream>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 참고 : http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220574993422
 
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
	
	//*2: 큐-각 상태를 "행*100+열"의 해시값으로 사용   
	queue<int> Q;
	Q.push(0);
	
	//이동횟수
	int result = 1;
	
	/*
	본래 while문은 queue가 비지 않아야 돌릴 수 있지만
	이 경우는 항상 도착 가능한 경우만 주어짐  
	*/ 
	while(1){
		int qSize = Q.size();
		//*4 : 이걸로 result, 단계를 구분  
		for(int i=0; i<qSize; i++){
			int r = Q.front()/100; 
			int c = Q.front()%100;	
			Q.pop();
			
			//도착한 경우
			if(r==N-1 && c==M-1){
				printf("%d\n",result);
				return 0;
			} 
			
			//*3: 4방향을 각각하는 것이 아니라 _cord배열 이용!  
			for( int d=0; d<4; d++){
				
				//4방향 탐색 
				int nr = r + row_cord[d];
				int nc = c + col_cord[d];
				
				//미로 바깥 차단 
				if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
				
				//벽인 경우 차단
				if(!map[nr][nc]) continue;
				
				//방문한 위치라면 패스 
				if(visited[nr][nc]) continue;
				  
				//위 경우가 아니라면 방문 표시 + 큐에 추가
				visited[nr][nc] = true;
				Q.push(nr*100+nc); 
			} 
		}
		//*4 : result로 단계를 표시 
		result++; 
	}
	
	
	return 0;
}
