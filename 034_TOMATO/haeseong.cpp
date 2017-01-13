#include <cstdio>
#include <queue>	// std::queue
#include <utility>	// std::pair
using namespace std;

int M, N;
int t[1002][1002];

bool isRipe()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (t[i][j] == 0)
                return false;
    return true;
}

int bfs()
{
    queue<pair<int, int> > q;
    pair<int, int> v;
    int dx, dy, time;
    int delta[4][2] = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 }
    };
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (t[i][j] == 1)
                q.push(make_pair(i, j));
    
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            dx = v.first  + delta[i][0];
            dy = v.second + delta[i][1];
            
            if (t[dx][dy] == 0) {
                q.push(make_pair(dx, dy));
                t[dx][dy] = t[v.first][v.second] + 1;
                time = t[dx][dy];
            }
        }
    }
    
    return time;
}

int main()
{
    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++)
            t[i][j] = -1;
    
    scanf("%d %d", &M, &N);
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &t[i][j]);
    
    if (isRipe())
        printf("0\n");
    
    int answer = bfs()-1;
    
    if (isRipe())
        printf("%d\n", answer);
    else
        printf("-1\n");
    
    return 0;
}
