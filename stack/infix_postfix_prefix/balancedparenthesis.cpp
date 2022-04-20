#include<bits/stdc++.h>
using namespace std;
bool balanced_paraenthesis(string s)
{
    stack<char> st;
    for(int i = 0; i<s.length();i++){
         if(s[i]=='(' || s[i]=='{' || s[i]=='[')
         {
             st.push(s[i]);
         }
         else if(s[i]==')'){
                  if(!st.empty() && st.top()=='('){
                      st.pop();
                  }
                  else{
                      return false;
                  }
                }
         else if(s[i]=='}'){
                  if(!st.empty() && st.top()=='{'){
                      st.pop();
                  }
                  else{
                      return false;
                  }
                } 
        else if(s[i]==']'){
                  if(!st.empty() && st.top()=='['){
                      st.pop();
                  }
                  else{
                      return false;
                  }
               }
    }    
    
    if(!st.empty())
    {
        return false;
    }
    
    return true;
}
int main()
{

    
    cout<<balanced_paraenthesis("}");
}