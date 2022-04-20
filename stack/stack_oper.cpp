#include<iostream>
using namespace std;
#define n 100

class stack{
    int top;
    int* arr;
    public:
    
    stack(){
        arr=new int[n];
       top = -1;
    }

    void push(int x){
        if(top==n-1)
        {
            cout<<"stack is overflow";
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop(){
        if(top==-1)
        {
            cout<<"stack is empty";
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
    return top=-1;
    }
};

int main()
{
    stack st;
    stack st1;
    st1.push(1);
    cout<<st1.Top()<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;

}