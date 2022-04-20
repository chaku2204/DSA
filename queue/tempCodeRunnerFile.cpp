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