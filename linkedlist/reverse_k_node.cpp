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
    
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    } 
    temp->next=n;
}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }cout<<endl;
}
int length(node* head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
      l++;
    }
    return l;
}
node* reverseknode(node* &head,int k)
{
    int count=1;
    node* newtail;
    node* newhead;
    node* tail=head;
    int l=length(head);

    while(tail->next!=NULL)
    {
        if(count==l-k){
            newtail=tail;
        }
        if(count == l-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;

    return newhead;
     
}
int main()
{
   node* head=NULL;
   inserttail(head,1);
   inserttail(head,2);
   inserttail(head,3);
   inserttail(head,4);
   inserttail(head,5);
   inserttail(head,6);
   display(head);
   node* newhead=reverseknode(head,3);
   display(newhead);
}
