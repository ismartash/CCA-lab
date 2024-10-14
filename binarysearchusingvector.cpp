#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binarysearch(vector<int>v,int key,int n)
{
    sort(v.begin(),v.end());
    cout<<"sorted array"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int s=0;
    int e=v.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(v[mid]==key)
        {
            return mid;
        }
        else if(key>v[mid])
        {
            s=mid+1;
        }
         else
         {
            e=mid-1;
         }
         mid=s+(e-s)/2;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"enter element"<<endl;
        cin>>x;
        v.push_back(x);
    }
    cout<<endl;
    int key;
    cout<<"enter key to search in array"<<endl;
    cin>>key;
    int ans=binarysearch(v,key,n);
    if(ans==-1)
    {
        cout<<"key not exist in array"<<endl;
    }
    else
    {
        cout<<key<<" is present at index : "<<ans<<endl;
    }
    return 0;
}