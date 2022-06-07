#include<iostream>
using namespace std;
int a[100],max1,min1;
void Max_Min(int i,int j)
{
    int max2,min2,mid;
    if(i==j)
    {
        max1=min1=a[i];
    }
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max1=a[j];
            min1=a[i];
        }
        else
        {
            max1=a[i];
            min1=a[j];
        }
    }
    else
    {
       mid=(i+j)/2;
        Max_Min(i,mid);
        max2=max1,min2=min1;
        Max_Min(mid+1,j);
        if(max1<max2)
        {
            max1=max2;
        }
        if(min1>min2)
        {
            min1=min2;
        }
    }
}
int main()
{
 int i, num;
 cout<<"Enter no. of elements:";
 cin>>num;
 cout<<"Enter the numbers : \n";
 for (i=1;i<=num;i++)
  cin>>a[i];

 max1 = a[0];
 min1 = a[0];
 Max_Min(1, num);
 cout<<"MAX NO.:"<<max1<<endl;
 cout<<"MIN NO.:"<<min1<<endl;

 return 0;
}
