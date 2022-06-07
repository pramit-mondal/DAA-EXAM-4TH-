#include <iostream>
#include <fstream>
using namespace std;
#define V 9
int graph[10][10],n;

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
                infile >> graph[i][j]; // read a graph from file
            }
        }
    }
    
}


int minkey(int *key, bool *mstSet)
{
    int min = 999, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
// constructed MST stored in parent[]
void printMST(int *parent, int s)
{
    int t = 0;
    cout << "Edge \tWeight\n";
    for (int i = 0; i < n; i++)
    {
        if(i==s)
            continue;
        else{    
           cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
           t = t + graph[i][parent[i]];
        }   
    }
    cout << "Minimum cost :" << t;
}
void primMST(int s)
{
    read();
    int parent[V];

    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = 9999, mstSet[i] = false;

    key[s] = 0;
    parent[s] = -1;
    for (int count = 0; count < V - 1; count++)
    {

        int u = minkey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, s);
}

int main()
{

    int s;
    cout << "Starting vertex is :";
    cin >> s;

    primMST(s);

    return 0;
}