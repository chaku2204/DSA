#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int> s1;
    public:
    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if(s1.empty())
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        
        int ele = s1.top();
        s1.pop();
        if(s1.empty())
        {
            return;
        }
         pop();
         s1.push(ele);
    }

    int peek()
    {
        if(s1.empty())
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }

        int ele=s1.top();
        s1.pop();
        if(s1.empty())
        {
            return ele;
        }
        int item = peek();
        s1.push(ele);
        return item;
    }

    bool empty()
    {
        if(s1.empty())
        {
            return 1;
        }
        return 0;
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

