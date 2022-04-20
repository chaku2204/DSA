#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^' || c=='$'){
        return 3;
    }
    else if(c=='/' || c=='*'){
    return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else 
    return -1;
}

string infixtoprefix(string s)
{
     reverse(s.begin(),s.end());
     int count=0;
     while(count!=s.length())
     {
         if(s[count]==')'){
             s[count]='(';
             count++;
         }
         else if(s[count]=='('){
             s[count]=')';
             count++;
         }
         else
         count++;
    }
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
              if(!st.empty()){
                  st.pop();
              }
          }
          else
            {
    
                if(!st.empty() && (prec(st.top())==prec(s[i]))){
                    if( (st.top()=='^' && s[i]=='^')||(st.top()=='^' && s[i]=='$')||
                        (st.top()=='$' && s[i]=='^')||(st.top()=='$' && s[i]=='$'))
                         {
                             while(!st.empty() && prec(st.top())>=prec(s[i])){
                            ans+=st.top();
                              st.pop();
                             }
                         }
                }
                
                while(!st.empty() && (prec(st.top())>prec(s[i])))
                {
                   /* if(prec(st.top())==prec(s[i])){
                       if((st.top()=='^' && s[i]=='^')||(st.top()=='^' && s[i]=='$')||
                        (st.top()=='$' && s[i]=='^')||(st.top()=='$' && s[i]=='$'))
                         {
                            ans+=st.top();
                              st.pop();
                             continue;
                         }
                        break;
                    }*/
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
    

      reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s = "k+l-m*n+(o^p)*w/u/v*t+q^j^a";
    cout<<infixtoprefix(s);
   //k+l-m*n+(o^p)*w/u/v*t+q
}