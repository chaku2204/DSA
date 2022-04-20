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

int search(int inorder[], int start, int end, int cur)
{
    for(int i = start; i<=end; i++){
        if(inorder[i]==cur){
            return i;
        }
    }
    return -1;
}

node* buildtree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if(start > end){
        return NULL;
    }

    int cur = preorder[idx];
    node* Node = new node(cur);
    idx++;
    if(start==end){
        return Node;
    }
    int pos = search(inorder, start, end, cur);
    Node->left = buildtree(preorder, inorder, start, pos-1);
    Node->right = buildtree(preorder , inorder, pos+1, end);
    return Node;
}

void inorderprint(node* root){

    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->info<<" ";
    inorderprint(root->right);

}
int main()
{
    int preorder[]={1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    
    node* root = buildtree(preorder, inorder, 0, 6);
    inorderprint(root);
}