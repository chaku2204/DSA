#include<bits/stdc++.h>
using namespace std;
int countpathmez(int n,int m,int i,int j)
{
    if(i==n-1 && j==m-1)
    {
        return 1;
    }
    if(i>=n || j>=m)
    {
        return 0;
    }

    int count  = 0;
    count=countpathmez(n,m,i+1,j)+countpathmez(n,m,i,j+1);
    return count;
}
int main()
{
    cout<<countpathmez(2,4,0,0);
}