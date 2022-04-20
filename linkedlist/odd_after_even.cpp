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
void oddaftereven(node* &head)
{
    node* odd = head;
    node* evenfirst = head->next;
    node* even = evenfirst;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next = evenfirst;
    if(odd->next==NULL)
    {
        even->next=NULL;
        return;
    }
}

void display(node* head)
{
       node* temp = head;
         while(temp!=NULL){
        cout<<(*temp).info<<" ";
        temp=(*temp).next;
    }cout<<endl;
}
int main()
{
    node* head=NULL;
    for(int i = 1; i<7; i++)
    {
    inserttail(head,i);
    }
    display(head);
    oddaftereven(head);
    display(head);

}