#include<bits/stdc++.h>
using namespace std;
struct node{
    public:
    int info;
    node* left;
    node* right;
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
    }
};
int main()
{
  struct node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  cout<<root->left->info<<endl;
}

