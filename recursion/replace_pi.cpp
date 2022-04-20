#include<bits/stdc++.h>
#include<string>
using namespace std;
string replace(string s)
{

    if(s.length()==0)
    {
        return "";
    }
    string ans = replace(s.substr(1));
    string pi = "3.14";
    if(s[0]=='p' && s[1]=='i')
    {
    return (pi+(ans.substr(1)));
    }
    else
    return (s[0]+ans);
} 

int main()
{
    cout<<replace("pippippi");
}