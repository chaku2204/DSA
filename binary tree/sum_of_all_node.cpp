#include<bits/stdc++.h>
using namespace std;
struct node{
    int info;
    node* left;
    node* right;
    node(int val){
        info = val;
        left = NULL;
        right = NULL;
    }
};

int countnode(node* root){
    if(root==NULL){
        return 0;
    }
    return countnode(root->left)+countnode(root->right)+root->info;
}

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<countnode(root);
}