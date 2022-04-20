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

int hight_binary_tree(node* root){
    if(root==NULL){
        return 0;
    }
    return (max(hight_binary_tree(root->left),hight_binary_tree(root->right)))+1;
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
     root->right->right->left = new node(8);

    cout<<hight_binary_tree(root);
}