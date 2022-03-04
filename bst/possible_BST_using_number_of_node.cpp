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

vector<node*> constructtree(int start, int end){
    vector<node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++){
        vector<node*> leftsubtree = constructtree(start, i-1);
        vector<node*> rightsubtree = constructtree(i+1, end);
        
        for(int j=0; j<leftsubtree.size(); j++){
            node* left = leftsubtree[j];
            for(int k = 0; k<rightsubtree.size(); k++){
                node* right = rightsubtree[k];
                node* root = new node(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        } 
        
    }
    return trees;
}
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->info<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
      vector<node*> trees = constructtree(1,3);
      for(int i = 0; i<trees.size(); i++){
          preorder(trees[i]);
          cout<<endl;
      }

}