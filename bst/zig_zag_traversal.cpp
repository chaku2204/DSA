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
void zigzagtraversal(node* root){
   if(root==NULL){
       return;
   }
   stack<node*> curlevel;
   stack<node*> nextlevel;

   bool lefttoright = true;
   curlevel.push(root);
   while(!curlevel.empty()){
       
       node* temp = curlevel.top();
       curlevel.pop();
       if(temp){

           cout<<temp->info<<" ";
           
           if(lefttoright){
               if(temp->left){
                   nextlevel.push(temp->left);
               }
               if(temp->right){
                   nextlevel.push(temp->right);
               }
           }

           else{
               if(temp->right){
                   nextlevel.push(temp->right);
               }
               if(temp->left){
                   nextlevel.push(temp->left);
               }
           }
        }
       if(curlevel.empty()){
           lefttoright = !lefttoright;
           swap(curlevel,nextlevel);
         }

   }
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
    
    zigzagtraversal(root);
}