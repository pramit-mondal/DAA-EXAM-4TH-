#include<iostream>
using namespace std;
int i,j,k,a,b,u,v,n,ne=1;
int min1,mincost=0,cost[9][9],parent[9];

int find(int i )
{
    while(parent[i]) 
      i=parent[i];
    return i;
}
int uni(int i, int j)
{
  if (i != j)
  {
    parent[j] = i;
    return 1;
  }
 
  return 0;
}

void krushkal()
{
  cout<<"The edges of Minimum Cost Spanning Tree are\n";
  while (ne < n)
  {
    for (i = 1, min1 = 999; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        if (cost[i][j] < min1)
        {
          min1 = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }
 
    u = find(u);
    v = find(v);
 
    if (uni(u, v))
    {
      printf("%d edge (%d,%d) =%d\n", ne++, a, b, min1);
      mincost += min1;
    }
 
    cost[a][b] = cost[b][a] = 999;
  }
 
  cout<<"MINIMUM COST ="<<mincost;
 

}
int main()
{
  
 
 cout<<"enter no. of vertices:"<<endl;
 cin>>n;
 
  cout<<"\nEnter the cost adjacency matrix:"<<endl;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0)
        cost[i][j] = 999;
    }
  }
  krushkal();
  return 0;
}