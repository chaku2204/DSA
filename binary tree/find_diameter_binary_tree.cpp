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
int calcheight(node* root){
    if(root==NULL){
        return 0;
    }

    return max(calcheight(root->left),calcheight(root->right))+1;
}

int calcdiameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lhight = calcheight(root->left);
    int rhight = calcheight(root->right);
    int currdiameter = lhight+rhight+1;

    int ldiameter = calcdiameter(root->left);
    int rdiameter = calcdiameter(root->right);

    return max(currdiameter,max(ldiameter,rdiameter));
}

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    
     root->left->right->left = new node(8);


    cout<<calcdiameter(root);
}