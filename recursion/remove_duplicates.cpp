#include<iostream>
#include<string>
using namespace std;
string moveall(string s)
{
    if(s.length()==0)
    {
        return "";
    }
     string ans = moveall(s.substr(1));
    
     if(s[0]==ans[0])
     {
         return ans;
     }
     return (s[0]+ans);
}
int main()
{
    cout<<moveall("aabdddeeefc");
}