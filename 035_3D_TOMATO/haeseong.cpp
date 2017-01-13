#include <cstdio>
#include <queue>	// std::queue
using namespace std;

struct vertex {
	int x;
	int y;
	int z;
};

int M, N, H;
int t[102][102][102];

bool isRipe()
{
	// H * N * M
    for (int i=1; i<=H; i++)
        for (int j=1; j<=N; j++)
			for(int k=1; k<=M; k++)
            	if (t[i][j][k] == 0)
                	return false;
    return true;
}

int bfs()
{
    queue<struct vertex> q;
	struct vertex v;
    int dx, dy, dz, time;
    int delta[6][3] = {
        { 0, 1, 0},
        { 0,-1, 0},
        { 1, 0, 0},
        {-1, 0, 0}, 
        { 0, 0, 1},
        { 0, 0,-1}
    };
    
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= N; j++)
    	    for (int k = 1; k <= M; k++)
            	if (t[i][j][k] == 1)
                	q.push((struct vertex){i,j,k});
    
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int i = 0; i < 6; i++) {
            dx = v.x + delta[i][0];
            dy = v.y + delta[i][1];
			dz = v.z + delta[i][2];
            
            if (t[dx][dy][dz] == 0) {
                q.push((struct vertex){dx,dy,dz});
                t[dx][dy][dz] = t[v.x][v.y][v.z] + 1;
                time = t[dx][dy][dz];
            }
        }
    }
    
    return time;
}

int main()
{
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++)
    		for (int k = 0; k < 102; k++)
        	    t[i][j][k] = -1;
    
    scanf("%d %d %d", &M, &N, &H);
    
    for (int k = 1; k <= H; k++)
    	for (int i = 1; i <= N; i++)
        	for (int j = 1; j <= M; j++)
            	scanf("%d", &t[k][i][j]);
    
    if (isRipe())
        printf("0\n");
    
    int answer = bfs()-1;
    
    if (isRipe())
        printf("%d\n", answer);
    else
        printf("-1\n");
    
    return 0;
}
