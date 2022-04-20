#include<bits/stdc++.h>
using namespace std;
struct node{
    int info;
    node* left;
    node* right;
    node(int val){
        cout<<"create node"<<endl;
        info = val;
        left = NULL;
        right = NULL;
    }
};

int height(node* root)
{
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return (max(lh,rh)+1);
}

bool balancedheight(node* root)
{
    if(root == NULL){
        return true;
    }

    if(balancedheight(root->left) == false){
        return false;
    }

    if(balancedheight(root->right) == false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh) <= 1){
        return true;
    }
    else 
    return false;
}

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    
    root->left->left = new node(4);
    

    cout<<balancedheight(root);
}