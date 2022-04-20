#include<iostream>
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

class queue{
    node* front;
    node* back;
    public:
    queue(){
        front = NULL;
        back = NULL;
    }
   void push(int x)
   {
       node* n = new node(x);
       if(front==NULL){
           front=n;
           back=n;
           return;
       }
       back->next=n;
       back=n;
   }

   void pop()
   {
       if(front == NULL){
           cout<<"queue is empty"<<endl;
           return;
       }
       node* todelete = front;
       front = front->next;

       delete todelete;
   }

   int peek()
   {
       if(front == NULL){
           cout<<"queue is empty"<<endl;
           return -1;
       }
        return front->info;
   }

   bool empty()
   {
       if(front == NULL){
           cout<<"queue is empty"<<endl;
           return true;
       }
       return false;
   }
};

int main()
{
    queue qu;
    for(int i = 1; i<=8;i++)
    {
        qu.push(i);
    }
     qu.pop();
    cout<<qu.peek()<<endl;
    for(int i = 1; i<8; i++){
        qu.pop();
    }
    cout<<qu.empty();
}

