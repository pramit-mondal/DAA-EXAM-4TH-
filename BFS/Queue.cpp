#include<iostream>
using namespace std;

int font=-1,rear=-1,q[10];
int isempty()
{
    if(rear == font)return 1;
    else return 0;
}
int isfull()
{
    if(rear=rear-1)return 1;
    else return 0;
}
int insert(int val)
{
       rear=rear+1;
       q[rear]=val;
}
int del()
{
    if(isempty()){
        cout<<"queue is empty.";
    }
    else{
        font=font+1;
        cout<<"Deleted elememt is "<<q[font];
        return q[font];
    }
}