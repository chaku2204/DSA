#include<bits/stdc++.h>
using namespace std;
bool pairsum(int a[],int n,int k)
{
    int low = 0;
    int high = n-1;
    while(low<high)
    {
        if(a[low]+a[high]<k)
        {
            low++;
        }
        else if(a[low]+a[high]>k)
        {
            high--;
        }
        else {
            cout<<low<<" "<<high<<endl;

            low++;
            high--;
        }
         
    }
    return false;
}
    
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<pairsum(a,n,k);

       
}
    
    
    
    
