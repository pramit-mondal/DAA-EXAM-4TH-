#include <iostream>
#include <fstream>
using namespace std;
int g[10][10], n, m, x[10] = {0};
void read()
{
    fstream infile;
    infile.open("abc.txt", ios::in);
    if (!infile)
    {
        cout << "Error";
    }
    else
    {
        infile >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                infile >> g[i][j];
            }
        }
    }
}
void next_value(int k)
{
    int j;
    read();
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (j = 1; j <= k - 1; j++)
        {
            if (g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (k == j)
            return;
    }
}
void mcoloring(int k)
{
    while (1)
    {
        next_value(k);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << "\t " << x[i];
            }
        }
        else
        {
            mcoloring(k + 1);
        }
    }
}
int main()
{

    printf("Enter the no. of colours:");
    scanf("%d", &m);
    read();
    mcoloring(1);
    return 0;
}
