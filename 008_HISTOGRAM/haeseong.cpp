#include <cstdio>
#include <stack>		// std::stack
#include <algorithm>	// std::max
using namespace std;

int N;	// 1 <= N <= 100,000
int h[100000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &h[i]);
    
    stack<int> s;
    int answer = 0;
    int tmpHeight;
    s.push(-1);
    for(int i=0; i<N; i++) {
        if(s.empty()) {
            s.push(i);
            continue;
        }
        
        if(h[s.top()] <= h[i]) {
            s.push(i);
        }
        else {
            while(!s.empty() && h[s.top()] > h[i]) {
                tmpHeight = h[s.top()];
                s.pop();
                answer = max(answer, (i-s.top()-1)*tmpHeight);
            }
            s.push(i);
        }
    }
    
    while(!s.empty() && s.top()!=-1) {
        tmpHeight = h[s.top()];
        s.pop();
        answer = max(answer, (N-s.top()-1)*tmpHeight);
    }
    
    printf("%d\n", answer);
    
    return 0;
}
