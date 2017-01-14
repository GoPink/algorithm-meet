#include <iostream>

using namespace std;

int N;

void star(int modN, int i,int j)
{
    if( (i / modN) % 3 == 1 && (j / modN) % 3 == 1)
        printf(" ");
    else
    {
        if(modN/3 == 0)
            printf("*");
        else
            star(modN/3,i,j);
    }
}
int main() {
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            star(N,i,j);
        printf("\n");
    }
    return 0;
}
