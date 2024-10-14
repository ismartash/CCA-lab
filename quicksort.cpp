#include<iostream>
using namespace std;
int partition(int arr[],int first,int last,int n)
{
    int pivot=arr[last];
    int j=first;
    int i=first-1;
     for(int j=first;j<last;j++)
     {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
     }
     swap(arr[i+1],arr[last]);
     return i+1;
}
void quicksort(int arr[],int first,int last,int n)
{
    if(first>=last)
    {
        return ;
    }
    else
    {
    int ash=partition(arr,first,last,n);
    quicksort(arr,first,ash-1,n);
    quicksort(arr,ash+1,last,n);
    }
}
int main()
{
    int n;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    int first=0;
    int last=n-1;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter elements"<<endl;
        cin>>arr[i];
    }
    quicksort(arr,first,last,n);
    cout<<"sorted array using quick sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }   
    return 0;
}