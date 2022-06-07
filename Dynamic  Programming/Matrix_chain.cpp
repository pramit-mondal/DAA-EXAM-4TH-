#include<iostream>
using namespace std;
int MCO(int arr[],int n)
{
    int m[n][n]={0};
    int s[n][n]={0};
    int min=9999,q,j;
    for(int d=1;d<n;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            j=i+d;
            for(int k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+arr[i-1]*arr[j]*arr[k];
                if(min>q)
                {
                    min=q;
                    s[i][j]=k;
                }
                m[i][j]=min;
            }
        }
    }
    return m[1][n-1];
}
int main()
{
    int arr[]={2,3,4,5,6};
    int n=sizeof(arr)/sizeof(int);
    cout<<MCO(arr,n)<<endl;
    return 0;    
}
