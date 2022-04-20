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
node* reversek(node* &head,int k)
{
    node* currptr=head;
    node* prevptr=NULL;
    node* nextptr;
    int count = 0;
    while(currptr!=NULL && count<k)
    {
        nextptr = currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reversek(nextptr,k);
     }
     return prevptr;
}


int main()

{
   node* head = NULL;
   int k = 3;
   inserttail(head,1);
   inserttail(head,2);
   inserttail(head,3);
   inserthead(head,4);
   inserttail(head,5);
   
   
   display(head);
   node* newhead = reversek(head,k);

   display(newhead);
   

}
