#include<iostream>
#include<queue>
using namespace std;
class stack{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int x)
    {
        q1.push(x);
    }

    void pop()
    {
         if(q1.empty())
         {
             cout<<"stack is empty"<<endl; 
             return;
         }
         
         while(q1.size()!=1)
         {
             q2.push(q1.front());
             q1.pop();
         }
         
         q1.pop();
         queue<int> temp=q1;
         q1 = q2;
         q2 = temp;
    }

    int Top(){
        if(q1.empty())
         {
             return -1;
         }
         
         while(q1.size()!=1)
         {
             q2.push(q1.front());
             q1.pop();
         }
         int ans = q1.front();
         q2.push(ans);
         q1.pop();
         queue<int> temp = q1;
         q1 = q2;
         q2 = temp;
         return ans;
     }

     bool empty()
     {
         if(q1.empty())
         {
             return 1;
         }
         return 0;
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
