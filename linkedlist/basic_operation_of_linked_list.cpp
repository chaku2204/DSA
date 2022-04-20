#include<bits/stdc++.h>
using namespace std;
class node{
     public:
    int info;
   
    node* next;
     
    node(int val){
        info = val;
        next = NULL;
    }
};
void inserthead(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL){
       head=n;
       return;
    }
    (*n).next = head;
    head=n;
}

void inserttail(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }

    node* temp = head;
    while((*temp).next!=NULL){
       temp = (*temp).next;
    }
    (*temp).next=n;
}
bool search(node* head,int key)
   {
       node* temp = head;
       while(temp!=NULL){
           if(temp->info==key){
           return true;
           }
           temp=temp->next;
       }
       return false;
   }
void display(node* head)
{
       node* temp = head;
         while(temp!=NULL){
        cout<<(*temp).info<<" ";
        temp=(*temp).next;
    }cout<<endl;
}

void deletaion(node* &head,int key)
{
    node* temp = head;
    if(head==NULL){
        return;
    }
    if(head->info==key)
    {
        head = head->next;
        delete temp;
        return;
        
    }

    while(temp->next->info!=key){

        temp=temp->next;
        if(temp->next==NULL){
        cout<<"element not found"<<endl;
        return;
       }

    }
    
     node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
    
}

node* revers(node* head)
{
    node* current = head;
    node* prev = NULL;
    node* nextpt;
    while(current!=NULL)
    {
         nextpt=current->next;
         current->next=prev;

         prev=current;
         current=nextpt;
         
    }
    return prev;
}
node* reverserecur(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
     node* newhead = reverserecur(head->next);
     head->next->next=head;
     head->next = NULL;

     return newhead;

}
int main()
{
    node* head = NULL;

    
    inserthead(head,1);
    inserthead(head,2);
    inserthead(head,3);
    inserthead(head,4);
    
    display(head);
    deletaion(head,1);


   
   display(head);
    
}