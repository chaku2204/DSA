#include<iostream>
using namespace std;
int firstocc(int a[],int n,int i,int key)
{
    if(i==n)
    {
        return -1;
    }

    if(a[i]==key)
    {
        return i;
     }
     return firstocc(a,n,i+1,key);     
    
}
int lastocc(int a[],int n,int i,int key)
{ 
 

    if(i==n)
    {
        return -1;
    }
    int resta = lastocc(a,n,i+1,key);

    if(resta != -1){
        return resta;
    }

    if(a[i]==key){
    return i;
     }
     return -1;

}
int main()
{
  int n;
  cin>>n;
  int a[n];
for(int i = 0 ;i<n; i++)
{
  cin>>a[i];
}
  cout<<firstocc(a,n,0,2)<<" ";
  cout<<lastocc(a,n,0,2)<<" ";
}