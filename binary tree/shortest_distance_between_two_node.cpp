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

node* lca(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->info == n1 || root->info == n2){
        return root;
    }

    node* left = lca(root->left, n1, n2);
    node* right = lca(root->right, n1, n2);

    if(left!=NULL && right!=NULL){
        return root;
    }

    if(left==NULL && right==NULL){
        return NULL;
    }

    if(left!=NULL){
        return left;
    }

    return right;
}
int finddistance(node* root, int key, int dist){
     if(root == NULL){
         return -1;
     }

     if(root->info==key){
         return dist;
     }

    int left = finddistance(root->left, key, dist+1);
    if(left != -1){
        return left;
    }
    return finddistance(root->right, key, dist+1);
     
}

int distancebw(node* root,int n1, int n2){
    node* LCA = lca(root, n1, n2);

    int d1 = finddistance(LCA, n1, 0);
    int d2 = finddistance(LCA, n2 ,0);

    return d1+d2;
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
    int n2 = 8;
    
    cout<<distancebw(root,n1,n2);
}