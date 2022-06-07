#include<iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int pertirion(int arr[],int l,int r)
{
   int pivot=arr[r];
   int i=l-1;
   for(int j=l;j<r;j++)
   {
       if(arr[j]<pivot)
       {
           i++;
           swap(arr,i,j);
       }
   }
   swap(arr,i+1,r);
   return i+1;
}

void Quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int  pi=pertirion(arr,l,r);
        Quicksort(arr,l,pi-1);
        Quicksort(arr,pi+1,r);
    }
}
int main()
{
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(int);
    Quicksort(arr,0,n-1);
    cout<<"After Quick sort the array looks like: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}