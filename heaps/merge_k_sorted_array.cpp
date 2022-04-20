#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    vector<vector<int>> v;
    for(int i = 0; i<k; i++){
        int size;
        cin>>size;
        vector<int> temp;
        for(int j = 0; j<size; j++){
            int val;
            cin>>val;
            temp.push_back(val);
        }
        v.push_back(temp);
    }
    vector<int> idx(k,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i = 0; i<k; i++){
        pair<int,int> p;
        p.first = v[i][0];
        p.second = i;
        pq.push(p);
    }
    
    vector<int> ans;
    while(!pq.empty())
    {
        pair<int,int> x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        if(idx[x.second]+1 < v[x.second].size()){
            pair<int,int> a;
            a.first = v[x.second][idx[x.second]+1];
            a.second = x.second;
            pq.push(a);
        }
        idx[x.second]+=1;
    }

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    
 }