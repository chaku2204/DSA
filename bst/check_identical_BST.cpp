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

bool checkIdenticalBST(node* root1,node* root2)
{
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else {
        
        bool cond1;
        bool cond2;
        bool cond3;
        if(root1->info == root2->info){
            cond1 = true;
        }
        
        bool left = checkIdenticalBST(root1->left,root2->left);
        bool right = checkIdenticalBST(root1->right,root2->right);
        if(left == true){
             cond2 = true;
        }
        if(right == true){
             cond3 = true;
        }

        if(cond1 && cond2 && cond3){
            return true;
        }
        else
         return false;
    
    }
}

int main()
{
    node* root1 = new node(8);
    root1->left = new node(3);
    root1->right = new node(10);
    root1->left->left = new node(1);

    node* root2 = new node(8);
    root2->left = new node(3);
    root2->right = new node(10);
    root2->left->left = new node(1);
    
    cout<<checkIdenticalBST(root1,root2);
}