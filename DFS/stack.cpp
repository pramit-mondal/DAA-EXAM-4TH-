#include<iostream>
using namespace std;
#define max 5
int arr[max],top=-1;
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if(top==max-1)
    {
        return 1;

    }
    return 0;
}
void push(int s)
{
   
      top=top+1;
      arr[top]=s;
    
}
int pop()
{
        top=top-1;
        return arr[top];    
}
void display()
{
    if(top==-1)
    {
        cout<<"stack empty"<<endl;
    }
    else
    {
        cout<<"stack is-";
        for(int i=top;i>=0;i--)
        {
            cout<<"\n"<<arr[i];
        }
    }
}   