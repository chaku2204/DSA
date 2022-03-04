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

node* insertBST(node* root,int val){

    if(root==NULL){
        return new node(val);
    }
    
    if(val< root->info){
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right,val);
    }

    return root;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,10);
    
    inorder(root);
}