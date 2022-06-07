#include<iostream>
#include"stack.cpp"
#include<fstream>
using namespace std;
int g[10][10],n,visited[10];
void read()
{
    fstream infile;
    infile.open("abc.txt", ios::in);
    if (!infile)
    {

        printf("\nError to open the file\n");
        exit(1);
    }
    else
    {
        int  i,j;
        infile>>n;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                infile >> g[i][j]; // read a graph from file
            }
        }
    }
    
}
void DFS(int v)
{
    read();
    int u,w;
    for( u=0;u<v;u++)
        visited[u]=0;
    
   
    visited[v]=1;
     push(v);
    while(!isEmpty())
    {
        int  i=pop();
        cout<<"\t"<<i+'A';
        for(w=0;w<n;w++)
        {
            if(g[i][w]==1 && visited[w]==0)
            {
                push(w);
                visited[w]=1;
            }
        }
    }
    
}
int main()
{
    int s;
    cout<<"Enter the starting vertex:";
    cin>>s;
    DFS(s);
    return 0;
}
