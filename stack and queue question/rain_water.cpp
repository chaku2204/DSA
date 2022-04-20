#include<bits/stdc++.h>
using namespace std;
int rain_water(vector<int> a)
{
    int n = a.size(),i=0;
    int ans=0;
    stack<int> st;
    for(int i = 0; i<n; i++)
    {

        while(!st.empty() && a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int dif = i-st.top()-1;
            ans+= (min(a[st.top()],a[i]) - a[cur])*dif;
        }
        st.push(i);
        
    }
    return ans;
}
int main()
{
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &i:a){
            cin>>i;
        }
        cout<<rain_water(a);
}