#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1]; 
    int b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];  
    }
    for(int j=0;j<n2;j++)
    {
        b[j]=arr[mid+1+j];
    }
    int i=0;  
    int j=0;  
    int k=l;  
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
          arr[k]=a[i]; 
          k++;
          i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1) 
    {
    arr[k]=a[i];
    k++;
    i++;
    }
    while(j<n2)
    {
    arr[k]=b[j];
    k++;
    j++;
    }
}
void mergesort(int arr[],int l,int r,int n) 
{
    if(l>=r)  
    {
        return ;
    }
    else
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid,n);
        mergesort(arr,mid+1,r,n);
        merge(arr,l,mid,r);  
    }
}
int main()
{
    int n;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter elements"<<endl;
        cin>>arr[i];
    }
    mergesort(arr,0,n,n);
    cout<<"sorted array using merge sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}