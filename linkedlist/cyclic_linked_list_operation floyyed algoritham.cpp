#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int info;
    node* next;

    node(int val){
        info=val;
        next=NULL;
    }
};

void inserttail(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}
void inserthead(node* &head,int val)
{
    node*n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    n->next = head;
    head=n;
    
}   
void display(node* head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }cout<<endl;
}

void makecycle(node* &head,int pos){
    node* temp = head;
    node* setnode;
    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            setnode=temp;
        }
        temp=temp->next;
        count++;
    }

    temp->next = setnode;
}
bool checkcyclic(node* &head)
{
    node* first = head;
    node* second = head;
    while(second!=NULL && second->next!=NULL)
    {
      first=first->next;
      second=second->next->next;
      if(first==second){
          return true;
      }
    }
     return false;
}
void removecycle(node* &head)
{
    node* first = head;
    node* second = head;

    
    do
    {
        first=first->next;
        second=second->next->next;
    }while (first!=second);
    
    first=head;
    while (second->next!=first->next)
    {
        first=first->next;
        second=second->next;
    }
    second->next=NULL;
}

int main()
{
   node* head = NULL;
   int k = 2;
   inserttail(head,1);
   inserttail(head,2);
   inserttail(head,3);
   inserthead(head,4);
   inserttail(head,5);
   inserttail(head,6);
   display(head);
   
   makecycle(head,2);
   removecycle(head);
   display(head);
   

}
