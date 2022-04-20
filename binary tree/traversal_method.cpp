#include<bits/stdc++.h>
using namespace std;
struct node{
    public:
    int info;
    node* left;
    node* right;
    
    node(int val){
        info = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(struct node* root)
{
    if(root==NULL){
        return;
    }
    cout<<root->info<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->info<<" ";
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
    root->left->left->left = new node(8);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

     
}