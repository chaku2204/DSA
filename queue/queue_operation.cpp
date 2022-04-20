#include<iostream>
using namespace std;
#define n 100
class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
      arr = new int[n];
      front = -1;
      back = -1;
    }

    void push(int x){
        if(back == n-1){
            cout<<" queue is overflow"<<endl;
            return;
        }

        back++;

        arr[back] = x;
        if(front == -1){
            front++;
        }
    }

    void pop()
    {
        if(front==-1  || (front>back))
        {
            cout<<"queue is empty";
            return;
        }
        front++;
    }

    int peek()
    {
        if(front==-1  || (front>back))
        {
            cout<<"queue is empty";
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if(front==-1  || (front>back))
        {
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