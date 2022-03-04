#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int s;
    cin>>s;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int j = 0, i = 0, sum = 0;
    while(j<n && a[j]+sum<=s)
    {
        sum+=a[j];
        j++;
    }


    if(sum == s)
    {
        cout<<i<<" "<<j-1<<endl;
    }
    while(j<n)
    {
        sum+=a[j];
        while(sum > s)
        {
            sum-=a[i];
            i++;
        }
        
        if(sum==s)
        {
             cout<<i<<" "<<j<<endl;
            
        }
        j++;
    }
}

