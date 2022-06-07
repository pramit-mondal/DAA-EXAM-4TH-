#include<iostream>
#include<fstream>
using namespace std;

int graph[10][10],n;
void read()
{
    fstream infile;
    infile.open("abc.txt",ios::in);
    if(!infile)
    {
        cout<<"Error";
        exit(1);
    }
    else{
        infile>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                infile>>graph[i][j];
            }
        }
    }
}
int minKey(int *key,bool *mstSet)
{
    int min=999,minIndex;
    for(int i=0;i<n;i++)
    {
        if(mstSet[i]==false && key[i]<min)
        {
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void display(int *parent,int s)
{
   int t=0;
   cout<<"edge \t weight "<<endl;
   for(int i=0;i<n;i++)
   {
       if(i==s)
       {
           continue;
       }
       else{
           cout<<parent[i]<<" - "<<graph[i][parent[i]];
           t=t+graph[i][parent[i]];
       }
   }
   cout<<"Minimum  cost=="<<t<<endl;
}
int dijstra(int s)
{
    read();
    int parent[n],key[n];
    bool mstSet[n];

    for(int i=0;i<n;i++)
    {
        key[i]=999;
        mstSet[i]=false;
    }
    key[s]=0;
    parent[s]=-1;
    for(int count=0;count<n-1;count++)
    {
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]!=0 && !mstSet)
            {
                if(key[v]!=999 && key[v]>(key[u]+graph[u][v])){
                  key[v]=key[u]+graph[u][v];
                  parent[v]=u;
                }
            }
        }
    }
    display(parent,s);


}

int main()
{

    int s;
    cout << "Starting vertex is :";
    cin >> s;

    dijstra(s);

    return 0;
}