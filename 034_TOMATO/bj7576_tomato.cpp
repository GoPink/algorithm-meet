#include <iostream>
#include <queue>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int map[1002][1002];
int C,R;
queue<int> Q;

bool isRipeAll (){
	
	for( int i=1; i<=R; i++)
		for( int j=1; j<=C; j++)
			
			if(map[i][j]==0) return false;		
	
	return true;
} 


int main(int argc, char** argv) {	
	
    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++)
            map[i][j] = -1;
				
	
	cin >> C;
	cin >> R;
	
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++){
			cin >> map[i][j];
			if(map[i][j]==1) {
				Q.push(i*1001+j); 
				//printf("첫 큐에추가  %d\n",i*100+j);				
			}	
		}
	/*	
	for(int i=0; i<=R+1; i++){
	
		for(int j=0; j<=C+1; j++){
			printf("%d.",map[i][j]);			
		}
		printf("\n"	);
	}	
	*/		
	
	//is ripe all?
	if(isRipeAll())
		printf("0");
	
	//탐색
	int time;
	int row_cord[4] = {-1,1,0,0}; // 상수 변하면 안되는 값  
	int col_cord[4] = {0,0,-1,1};	
	
	
	while(!Q.empty()){

		//printf("현재 위치는 %d\n",Q.front());
		int curX = Q.front()/1001;
		int curY = Q.front()%1001;		
		Q.pop();
			
		//4방향 탐색
		for( int d=0; d<4; d++){
				
			int nx = curX + row_cord[d];
			int ny = curY + col_cord[d];
				
		
			if(map[nx][ny]==0){
				Q.push(nx*1001+ny);				
				map[nx][ny]=map[curX][curY]+1;
				time = map[nx][ny];
				//printf("탐색후 큐에추가  %d\n",nx*1000+ny);		
			}				 
		} 
		
			
	} 
	
	if(isRipeAll())
		printf("%d",time-1);
	else
		printf("-1");
	
	return 0;
}
