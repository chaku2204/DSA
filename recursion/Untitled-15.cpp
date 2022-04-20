#include<bits/stdc++.h>
using namespace std;
int countpathmez(int n,int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        return 1;
    }
    if(i>=n || j>=n)
    {
        return 0;
    }

    int count  = 0;
    count=countpathmez(n,i+1,j)+countpathmez(n,i,j+1);
    return count;
}
int main()
{
    cout<<countpathmez(3,0,0);
}