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

node* lca(node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->info == n1 || root->info == n2){
        return root;
    }

    node* leftlca = lca(root->left, n1, n2);
    node* rightlca = lca(root->right, n1, n2);

    if(leftlca!=NULL && rightlca!=NULL){
        return root;
    }

    if(leftlca != NULL){
        return leftlca;
    }
    else
       return rightlca;
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
    
    int n1 = 7;
    int n2 = 5;

    node*lca2 = lca(root,n1,n2);
    if(lca2 == NULL){
        cout<<"LCA doesn't exist"<<endl;
    } else {
        cout<<"LCA : "<<lca2->info<<endl;
    }
}