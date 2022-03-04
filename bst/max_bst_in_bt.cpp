#include<bits/stdc++.h>
using namespace std;
struct node{
    int info;
    node* left,*right;
    node(int val){
        info = val;
        left = NULL;
        right = NULL;
    }
};
struct info{
    int min;
    int max;
    int size;
    int ans;
    bool isBST;
};

info max_BST_IN_binary(node* root)
{
    if(root == NULL){
        return {INT_MIN, INT_MAX, 0, 0, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {root->info, root->info, 1,1,true};
    }

    info left = max_BST_IN_binary(root->left);
    info right = max_BST_IN_binary(root->right);
    info curr;
    curr.size = 1 + left.size + right.size;
    if(left.isBST && right.isBST && left.max < root->info && right.min > root->info)
    {
        curr.min = min(left.min,min(right.min,root->info));
        curr.max = max(left.max, max(right.max,root->info));
        curr.ans = curr.size;
        curr.isBST = true;
        
        return curr;
    }
    
    curr.ans = max(left.ans,right.ans);
    curr.isBST = false;
    
    return curr;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(0);
    root->right->right = new node(7);
    
    cout<<max_BST_IN_binary(root).ans;
    
}
