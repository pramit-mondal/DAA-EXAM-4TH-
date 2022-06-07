#include<iostream>
using namespace std;
void Merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1,n2=r-mid;
    int la[n1],ra[n2];
    for(int i=0;i<n1;i++)
    {
        la[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        ra[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(la[i]<ra[j])
        {
            arr[k]=la[i];
            i++;k++;
        }
        else
        {
            arr[k]=ra[j];
            j++;k++;
        }
    }
    while(i<n1)
    {
        arr[k]=la[i];
        i++;k++;
    }
    while(j<n2)
    {
        arr[k]=ra[j];
        j++;k++;
    }
}

void Mergesort(int arr[],int l,int r){
    if(l<r)
    {
        int mid=(l+r)/2;
        Mergesort(arr,l,mid);
        Mergesort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }
}
int main()
{
     int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(int);
    Mergesort(arr,0,n-1);
    cout<<"After Quick sort the array looks like: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}