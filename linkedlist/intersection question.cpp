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
    node* temp=head;
    while(temp->next!=NULL)
    {
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
int length(node* head)
{
    int l=0;
    node* temp = head;
    while(temp!=0)
    {
        temp=temp->next;
        l++;
    }
    return l;
}
void intersection(node* &head1, node* &head2, int pos)
{
     node* temp1=head1;
     while(1<pos)
     {
         temp1=temp1->next;
         pos--;
     }
     node* temp2=head2;
     while(temp2->next!=NULL)
     {
         temp2=temp2->next;
     }
     temp2->next=temp1;
}

int findintersection(node* &head1,node* &head2)
{
   int l1=length(head1);
    int l2=length(head2);
    int d;
    node* ptr1;
    node* ptr2;
    if(l1<l2){
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    else
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }

    while(0<d){
        ptr1=ptr1->next;
        if(ptr1==NULL)
        {
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2){
            return ptr1->info;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
  return -1;
}


int main()
{
    node* head1=NULL;
    node* head2=NULL;
    inserttail(head1,1);
    inserttail(head1,2);
    inserttail(head1,3);
    inserttail(head1,4);
    inserttail(head2,5);
    inserttail(head2,6);
    cout<<findintersection(head1,head2)<<endl;
    intersection(head1, head2, 3);
    
    display(head1);
    display(head2);
    cout<<findintersection(head1,head2)<<endl;
}