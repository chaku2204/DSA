#include<iostream>
#include<queue>
using namespace std;
class stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    
    public:
    stack(){
         n=0;
    }
    void push(int x)
    {
        q2.push(x);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        if(q1.empty())
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        q1.pop();
        n--;
    }

    int Top()
    {
        if(q1.empty())
        {
            return -1;
        }
        return q1.front();
    }

    bool empty()
    {
        if(q1.empty())
        {
            return 1;
        }
        return 0;
    }
    int size(){
        return n;
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
    cout<<st.size()<<endl;
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;
    
}
