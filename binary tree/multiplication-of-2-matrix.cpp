#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,m,n2;
    cin>>n1>>m>>n2;
    
    int a1[n1][m],a2[m][n2];

    for(int i = 0; i<n1; i++){
        for(int j = 0; j<m; j++){
            cin>>a1[i][j];
        }
    } 

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n2; j++){
            cin>>a2[i][j];
        }
    }


    int ans[n1][n2];
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            ans[i][j] = 0;
        }
    }

    
     for(int i = 0; i<n1; i++){
         for(int j = 0; j<n2; j++){
             for(int k = 0; k<m; k++){
                 ans[i][j] += a1[i][k]*a2[k][j];
             }
         }
     }

     for(int i = 0; i<n1; i++){
         for(int j = 0; j<n2; j++){
             cout<<ans[i][j]<<" ";
         }
         cout<<endl;
     }
           
}