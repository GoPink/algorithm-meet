#include <iostream>
#include <math.h>

typedef long long ll;
using namespace std;

class SegmentTree
{
private:
    ll* nodes;
    ll* A;
    
    ll init(int index, int start, int end)
    {
        if(start == end)
            nodes[index] = A[start];
        else
            nodes[index] =
            init(2*index+1, start, (start+end)/2) +
            init(2*index+2, (start+end)/2+1, end);
        
        return nodes[index];
    }
public:
    SegmentTree(int N, ll* A){
        int h = (int)ceil(log2(N));
        int node_size = 1 << (h+1);
        nodes = new ll[node_size];
        
        this->A = A;
        init(0, 0, N-1);
    }
    ~SegmentTree(){
        delete [] nodes;
    }
    ll getSum(int index, int start, int end, int left, int right)
    {
        //구하려는 범위가 밖에 있는 경우
        if(left > end || right < start)
            return 0;
        else if(left <= start && right >= end)
            return nodes[index];
        
        int mid = (start+end)/2;
        return getSum(index*2+1, start, mid, left, right) +
               getSum(index*2+2, mid+1, end, left, right);
    }
    void update(int changed_index, ll diff, int index, int start, int end)
    {
        if(changed_index < start || changed_index > end )
            return;
        
        nodes[index] += diff;
        
        if(start != end){
            int mid = (start + end)/2;
            update(changed_index, diff, index*2+1, start,mid);
            update(changed_index, diff, index*2+2, mid+1,end);
        }
    }
};

int main()
{
    ll A[1000001];
    int N,M,K;
    cin>>N>>M>>K;
    
    for(int i=0;i<N;i++)
        cin>>A[i];
    
    int C = M+K;
    
    SegmentTree st(N,A);
    
    while(C--)
    {
        int a,b;
        cin>>a>>b;
        if(a == 1)
        {
            ll c;
            cin>>c;
            
            ll diff= c-A[b-1];
            A[b-1]=c;
            st.update(b-1, diff, 0, 0, N-1);
        }
        else if(a == 2)
        {
            int c;
            cin>>c;
            cout<<st.getSum(0, 0, N-1, b-1, c-1)<<endl;
        }
    }
}
