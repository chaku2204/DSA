#include<bits/stdc++.h>
using namespace std;
bool redundant_parenthesis(string s)
{
    stack<char> st;
    
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='(')
            {
                  return true;
            }
            while(!st.empty() && (s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')){
                st.pop();
            }
            st.pop();
        }
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<redundant_parenthesis(s);
}