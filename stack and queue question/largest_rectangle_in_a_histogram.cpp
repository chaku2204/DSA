#include<bits/stdc++.h>
using namespace std;
int get_max_area(vector<int> &a)
{
    int n = a.size(), ans = 0, i = 0;
    stack<int> st;
    a.push_back(0);
    while(i<=n)
    {
       while(!st.empty() && a[st.top()] > a[i])
       {
           int t = st.top();
           int h = a[t];
           st.pop();
           if(st.empty()){
               ans = max(ans,h*i);
           } 
           else
           {
           int len = i-st.top()-1;
           ans = max(ans,h*len);
           }
       }
       st.push(i);
       i++;
    } 
   return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a)
    cin>>i;
    cout<<get_max_area(a)<<endl;
    
    



}