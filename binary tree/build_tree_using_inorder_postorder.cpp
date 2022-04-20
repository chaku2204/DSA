#include<bits/stdc++.h>
using namespace std;

struct Node{
    int info;
    Node* left;
    Node* right;

    Node(int val){
        info = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int cur){
    for(int i = start; i<=end; i++){
        if(inorder[i] == cur){
            return i;
        }
    }
    return -1;
}

Node* buildtree(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if(start > end){
        return NULL;
    }

    int cur = postorder[idx];
    Node* node = new Node(cur);
    idx--;

    if(start==end){
        return node;
    }
    int pos = search(inorder, start, end, cur);
    node->right = buildtree(postorder, inorder , pos+1, end);
    node->left =   buildtree(postorder, inorder, start, pos-1);
    return node;
}

void inorderprint(Node* root)
{
    if(root == NULL)
    {
        return;
    }
      inorderprint(root->left);
      cout<<root->info<<" ";
      inorderprint(root->right);
}

int main()
{
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    Node* root = buildtree(postorder, inorder, 0, 4);
    inorderprint(root);
}