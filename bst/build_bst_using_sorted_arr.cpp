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

node* build_bst_arr(int arr[],int start,int end){
    if(start > end){
        return NULL;
    }
   int mid = (start+end)/2;
   node* root = new node(arr[mid]);
   if(start == end){
       return root;
   }

   root->left = build_bst_arr(arr,start,mid-1);
   root->right = build_bst_arr(arr,mid+1,end);
   return root;
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->info<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int a[] = {1,2,3,4,5};
    node* root = build_bst_arr(a,0,4);
    preorder(root);

}