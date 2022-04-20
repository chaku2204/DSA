#include<iostream>
#include<stack>

using namespace std;
class queuee{
    stack<int> s1;
    stack <int> s2;
public:
    void push(int x){
        s1.push(x);
    }

    void pop()
    {
        if(s1.empty() && s2.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
         }
        }
        s2.pop();
    }
    
    int peek()
    {
        if(s1.empty() && s2.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
         }
        }
         return s2.top();
    }

    bool empty()
    {
        if(s1.empty() && s2.empty()){
            cout<<"queue is empty"<<endl;
            return 1;
        }
        return 0;

    }
};

int main()
{
    queuee qu;
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

