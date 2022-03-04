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

node* inordersucc(node* root){
    node* cur = root;
    while(cur && cur->left!=NULL){
        cur = root->left;
    } 
    return cur;
}

node* deleteINBST(node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->info){
        root->left = deleteINBST(root->left,key);
    }
    else if(key > root->info){
        root->right = deleteINBST(root->right,key);
    }
    else {

        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
        node* temp = inordersucc(root->right);
        root->info = temp->info;
        root->right = deleteINBST(root->right,temp->info);
        }
    }
    return root;
}
void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
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
    
    root = deleteINBST(root,6);
    inorder(root);

}