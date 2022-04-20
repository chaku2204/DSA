#include<bits/stdc++.h>
using namespace std;
struct node{
    int info;
    node* left, *right;

    node(int val){
        info = val;
        left = NULL;
        right = NULL;
    }
};

//case 1

void printsubtreenode(node* root,int k)
{
    if(root==NULL || k<0){
        return;
    }
    
    if(k==0){
        cout<<root->info<<" ";
        return;
    }
    printsubtreenode(root->left,k-1);
    printsubtreenode(root->right,k-1);
}

int printnodeatk(node* root,node* target,int k)
{
    if(root==NULL){
        
        return -1;
    }

    if(root==target){
        printsubtreenode(root,k);
        return 0;
    }

    int dl = printnodeatk(root->left, target, k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->info<<" ";
        }
        else {
            printsubtreenode(root->right,k-dl-2);
        }
       return dl+1;
    }

    int dr = printnodeatk(root->right, target, k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->info<<" ";
        }
        else {
            printsubtreenode(root->left,k-dr-2);
        }
       return dr+1;
    }

    return -1;
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

     
     printnodeatk(root,root->right->right->left,3);
}