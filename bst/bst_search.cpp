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
node* search(node* root,int key)
{
    if(root==NULL){
        return NULL;
    }
   if(root->info==key){
       return root;
   }
   if(root->info > key){
       return search(root->left,key);
   }

   return search(root->right,key);
}
int main()
{
    struct node* root = new node(5);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(8);
     

     if(search(root,3)==NULL){
         cout<<"key doesn't exist";
        }
    else
       cout<<"key exist";
}