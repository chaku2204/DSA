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

void sumreplace(node* root)
{
    if(root==NULL){
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);

    if(root->left != NULL){
        root->info += root->left->info;
    }

    if(root->right != NULL){
        root->info += root->right->info;
    }
}

void preorder(node* root){
    
    if(root == NULL){
        return;
    }
    cout<<root->info<<" ";
    preorder(root->left);
    preorder(root->right);
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
   sumreplace(root);
    preorder(root);
}