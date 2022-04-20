#include<bits/stdc++.h>
using namespace std;
bool palandrom(string s)
{
      stack<char> st;
      for(int i  = 0; i<s.length();i++)
      {
          st.push(s[i]);  
              
      }
      
      
      for(int i=0; i<s.length();i++)
      {
          if(s[i]!=st.top())
          {
              return false;
          }
          st.pop();
      }
      return true;
}
int main()
{
      string s;
      cin>>s;
      cout<<palandrom(s);
}