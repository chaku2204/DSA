#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int info;
    node* next;
    node* prev;
    node(int val){
        info=val;
        next=NULL;
        prev=NULL;
    }
};


void inserthead(node* &head,int val)
{
    node* n = new node(val);
    n->next=head;
    if(head!=NULL){
    head->prev=n;
    }
    head=n;
}

void inserattail(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    
    node* temp = head;
    while(temp->next!=NULL)
    {
         temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}


void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


void deletaion(node* &head,int pos){

    if(pos==1){
        node* todelete=head;
        head=head->next;
        head->prev=NULL;
        delete todelete;
        return;
    }
    node* temp=head;
    int count = 1;
    while(temp!=NULL && count<pos){
            temp=temp->next;
            count++;
    }
     temp->prev->next=temp->next;
     if(temp->next!=NULL){
     temp->next->prev=temp->prev;
     }

     delete temp;
}
int main()
{
      node* head=NULL;
      int n;
      cin>>n;
      for(int i = 1;i<=n;i++){
          inserattail(head,i);
      }
      inserthead(head,0);
     display(head);
     deletaion(head,7);
     display(head);

}
