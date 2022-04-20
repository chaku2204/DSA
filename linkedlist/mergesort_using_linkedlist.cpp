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
    
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head)
{
    node* temp= head;
    while(temp!=NULL)
    {
       cout<<temp->info<<" ";
       temp=temp->next;
    }cout<<endl;
}

node* mergsort(node* &head1,node* &head2)
{
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dynamic = new node(-1);
    node* ptr3 = dynamic;

    while(ptr1!=NULL && ptr2!=NULL)
    {
      if(ptr1->info < ptr2->info)
      {
         ptr3->next=ptr1;
         ptr1=ptr1->next;
      }
      else
      {
          ptr3->next=ptr2;
          ptr2=ptr2->next;
      }
      ptr3=ptr3->next;
    }

    while(ptr1!=NULL)
    {
         ptr3->next=ptr1;
         ptr1=ptr1->next;
         ptr3=ptr3->next;
    }

    while(ptr2!=NULL)
    {
        ptr3->next=ptr2;
        ptr2=ptr2->next;
         ptr3=ptr3->next;
    }

    return dynamic->next;
}
node* recmergsort(node* &head1, node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
     if(head2==NULL)
     {
         return head1;
     }


     node* result;

     if(head1->info < head2->info)
     {
         result = head1;
         result->next  = recmergsort(head1->next,head2);
     }
     else
     {
         result = head2;
         result->next = recmergsort(head1,head2->next);
     }
     return result;
}
int main()
{
      node* head1=NULL;
      node* head2=NULL;
      inserttail(head1,1);
      inserttail(head1,2);
      inserttail(head1,3);
      inserttail(head1,4);
      inserttail(head1,5);
      inserttail(head2,10);
      inserttail(head2,11);
      inserttail(head2,12);
      display(head1);
      display(head2);
      node* newhead = recmergsort(head1,head2);
      display(newhead);
}