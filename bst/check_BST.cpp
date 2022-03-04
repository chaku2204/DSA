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

bool checkbst(node* root,int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->info <= min){
        return false;
    }
    if(root->info >= max){
        return false;
    }

    bool leftvalid = checkbst(root->left,min,root->info);
    bool rightvalid = checkbst(root->right,root->info,max);
    return leftvalid and rightvalid;
}

int main()
{
    node* root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    
    

    if(checkbst(root, INT_MIN, INT_MAX)==true){
        cout<<"BST is valid";
    }
    else{
        cout<<"BST is invalid";
    }
}