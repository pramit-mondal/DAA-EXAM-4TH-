#include <iostream>
using namespace std;
void swap(int arr[],int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void heapify(int a[], int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[max])
    {
        max = l;
    }
    if (r < n && a[r] > a[max])
    {
        max = r;
    }
    if(max!=i)
    {
        swap(a,i,max);
        heapify(a,n,max);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a, i,0);
        heapify(a, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, n);
  
    cout << "Sorted array is \n";
    printArray(arr,n);
    return 0;
}
