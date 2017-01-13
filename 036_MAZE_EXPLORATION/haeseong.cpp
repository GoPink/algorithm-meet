#include <cstdio>
#include <queue>
using namespace std;

char map[102][102] = {0, };
char visit[102][102] = {0, };
int length[102][102] = {0, };
int delta[4][2] = {
    { 0, 1 },
    { 0, -1 },
    { 1, 0 },
    { -1, 0 }
};

void bfs(pair<int, int> v)
{
    int dx, dy;
    queue<pair<int, int> > q;
    
    visit[v.first][v.second] = 1;
    length[v.first][v.second] = 1;		// 시작점의 거리는 1 (문제에서주어짐)
    q.push(v);
    
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            dx = v.first + delta[i][0];
            dy = v.second + delta[i][1];
            if (map[dx][dy] == 1 && !visit[dx][dy])	{ // 길이 있고 방문하지 않았을 경우
                visit[dx][dy] = 1;
                length[dx][dy] = length[v.first][v.second] + 1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}

int main()
{
    int N, M;
    char c = 0;
    
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            do {
                scanf("%c", &c);
            } while (c == '\n');
            map[i][j] = c-'0';
        }
    }
    
    bfs(make_pair(1,1));
    
    printf("%d\n", length[N][M]);
    
    return 0;
}
