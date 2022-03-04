#include<bits/stdc++.h>
using namespace std;
int catlan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;

    for(int i = 0; i<=n-1; i++){
       res+= catlan(i)*catlan(n-i-1);
    }

    return res;
}
int main()
{
    cout<<catlan(4);

}