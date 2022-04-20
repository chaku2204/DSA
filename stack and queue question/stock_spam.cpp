#include<bits/stdc++.h>
using namespace std;
vector<int> stock_spam(vector<int> a)
{
    vector<int> ans;
    stack<pair<int,int>> st;
    for(int i = 0; i<a.size(); i++){
        int days=1;
        while(!st.empty() && st.top().first<=a[i]){
        days += st.top().second;
        st.pop();
        }
        st.push({a[i],days});
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a){
        cin>>i;
    }
     
     vector<int> ans = stock_spam(a);
     for(auto i : ans){
         cout<<i<<" ";
     }

}