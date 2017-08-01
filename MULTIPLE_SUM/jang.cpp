#include <iostream>

using namespace std;

int main()
{
    int N;
    int input[100001];
    
    cin>>N;
    
    for(int i=0;i<N;i++)
        cin>>input[i];
    
    long long int result=0;
    long long int sum = 0;
    
    for(int i=N-2;i>=0;i--)
    {
        sum += input[i+1];
        result += input[i]*sum;
    }
    cout<<result<<endl;
        
    
    return 0;
}
