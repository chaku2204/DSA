#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^' || c=='$')
    {
        return 3;
    }
    else if(c=='/' || c=='*')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
}

string infixtopostfix(string s)
{
    stack<char> st;
    string ans;
    for(int i = 0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else{
            
           while(!st.empty() && prec(st.top())>=prec(s[i])){
                  //if((st.top()=='^' && s[i]=='^')||(st.top()=='^' && s[i]=='$')||
                  //(st.top()=='$' && s[i]=='^')||(st.top()=='$' && s[i]=='$')){
                    //    break;
                    //}
               ans+=st.top();
                st.pop();
               }
               
               st.push(s[i]);
            }
        }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s;
    cout<<"enter infix expression"<<endl;
    cin>>s;
    cout<<infixtopostfix(s);
}