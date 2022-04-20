#include<bits/stdc++.h>
#include<string>
using namespace std;
bool ari(int a[],int n)
{
    if(n==1)
    {
        return true;
    }

    int rem = ari(a+1,n-1);
    if(a[0] < a[1] && ari)
    {
    return true;
    }
    else
    return false;
}
int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }

    cout<<ari(a,n);
     
    
}