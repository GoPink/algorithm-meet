/*********************************************
	22 Nov. 2016
	Haeseong Jeon
   
	1254. Making a Palindrome. 
	https://www.acmicpc.net/problem/1254

*********************************************/

#include <cstdio>
using namespace std;

char p[1001];               // length of string <= 1000
char d[1001][1001] = {0,};

int main()
{
    int i, j, k, N = 0;
    
    // input string
    scanf("%s", p);
    
	// length of string
    for(i=0; p[i]!=0; i++)
        N += 1;
    
    // determine whether [i,j] is palindrome or not.
    for(k=0; k<=N-1; k++) {
        for(i=0, j=i+k; i<=N-k && j<=N; i++, j++) {
            
            if(k==0) {
                // len == 1
                d[i][j] = '1';
            }
            else if(k==1) {
                // len == 2
                if(p[i] == p[j])
                    d[i][j] = '1';
                else
                    d[i][j] = '0';
            }
            else {
                // 3 <= len
                if(d[i+1][j-1]=='1' && p[i] == p[j]) {
                    d[i][j] = '1';
                }
                else
                    d[i][j] = '0';
            }
        }
    }
    
    // calculate how many characters we need (?)
    int result = 0;
    for(i=0; i<N; i++) {
        if(d[i][N-1]=='1') {
            result = i;
            break;
        }
    }
    
    // print answer
    printf("%d\n", result+N);
    
    return 0;
}

