#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int info;
    node* next;
    node(int val)
    {
        info=val;
        next=NULL;
    }
};
void inserthead(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        head->next=head;
        return;
    }
    node* temp = head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;

    
}
void inserttail(node* &head,int val)
{
     node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        head->next=head;
        return;
     }
     node* temp=head;
     while(temp->next!=head)
     {
         temp=temp->next;
     }
     temp->next=n;
     n->next=head;
}

void display(node* head)
{
    node* temp = head;
    while(temp->next!=head)
    {
       cout<<temp->info<<" ";
       temp=temp->next;
    }
    cout<<temp->info<<" ";
    cout<<endl;
}

int main()
{

    node* head=NULL;
    inserttail(head,2);
    inserttail(head,1);
    inserttail(head,4);
    inserttail(head,3);
    inserttail(head,5);
    inserthead(head,7);
    display(head);
}