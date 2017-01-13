#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int **graph;

void dfs(int n) {
    // visit n
    cout << n << " ";
    graph[n][0] = 1;
    
    // for child v of n
    for(int i=1; i<=N; i++) {
        // visit v
        if(graph[i][n] == 1 && graph[i][0] == 0) {
            dfs(i);
        }
    }
}

void bfs(int n) {
    for(int i=1; i<=N; i++)
        graph[i][0] = 0;
    
    queue<int> Q;
    // enqueue n
    Q.push(n);
    graph[n][0] = 1;
    
    while(!Q.empty()) {
        // Q pop
        int v = Q.front();
        Q.pop();
        // visit v
        cout << v << " ";
        
        // for child u of v
        for(int i=1; i<=N; i++) {
            // enqueue u
            if(graph[v][i] == 1 && graph[i][0] == 0) {
                graph[i][0] = 1;
                Q.push(i);
            }
        }
    }
    cout << endl;
}

int main()
{
    //freopen("dfs_bfs.txt", "r", stdin);
    
    cin >> N;
    cin >> M;
    cin >> V;
    
    graph = new int*[N+1];
    for(int i=0; i<N+1; i++)
        graph[i] = new int[N+1];
    
    for(int i=0; i<N+1; i++)
        for(int j=0; j<N+1; j++)
            graph[i][j] = 0;
    
    int a, b;
    for(int i=0; i<M; i++) {
        cin >> a;
        cin >> b;
        graph[a][b] = graph[b][a] = 1;
    }
    
    dfs(V);
    cout << endl;
    bfs(V);
    
    return 0;
}
