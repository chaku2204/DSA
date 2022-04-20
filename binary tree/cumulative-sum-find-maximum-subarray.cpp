#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int currentsum[n+1];
    currentsum[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        currentsum[i] = currentsum[i-1] + a[i-1];

    }


    int maxsum = INT_MIN;
    for(int i = 1; i<=n; i++)
    {
        int sum=0;
        for(int j = 0; j<i; j++)
        {
            sum = currentsum[i]-currentsum[j];
            maxsum = max(sum,maxsum);
        }
    }
    cout<<maxsum;
    return 0;
}