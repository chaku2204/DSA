#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int array[n];
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }

    int count=0;
    for(int i = 0; i<n; i++)
    {
        count=0;
        for(int j = i; j<n; j++)
        {
            count+=array[j];
            cout<<count<<endl;
            
        }
    }
    
}