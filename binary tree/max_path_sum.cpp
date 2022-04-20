#include<bits/stdc++.h>
using namespace std;
struct node{
    int info;
    node *left, *right;

    node(int val){
        info = val;
        left = NULL;
        right = NULL;
    }
};

int maxpathsumutil(node* root,int &ans)
{
    if(root==NULL){
        return 0;
    }

    int left = maxpathsumutil(root->left,ans);
    int right = maxpathsumutil(root->right,ans);

    int ansmax = max(max(root->info ,root->info+left+right)
                   ,max(root->info+left, root->info+right));
    
    ans = max(ans,ansmax);
    int singlepathsum = max(root->info, max(root->info + left, root->info + right));
    return singlepathsum;
}
int maxpathsum(node* root){
    int ans = INT_MIN;
    maxpathsumutil(root,ans);
    return ans;
}

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(-3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(-7);
     root->right->right->left = new node(28);

    cout<<maxpathsum(root);
}