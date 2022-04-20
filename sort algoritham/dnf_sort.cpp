#include<bits/stdc++.h>
using namespace std;
void dnfsort(int a[], int n)
{
   int low = 0;
   int mid = 0;
   int high = n-1;
   while(mid<=high)
   {
       if(a[mid]==0){
       swap(a[mid],a[low]);
       low++;
       mid++;
       }
       else if(a[mid]==1){
           mid++;
       }
       else{
       swap(a[mid],a[high]);
           high--;
       }
    }
}
int main()
{
     int n;
     cin>>n;
     int a[n];
     for(int i = 0; i<n; i++){
         cin>>a[i];
     }
     dnfsort(a,n);

     for(int i = 0; i<n; i++){
         cout<<a[i]<<" ";
     }
}
