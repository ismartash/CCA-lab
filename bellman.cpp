#include<iostream>
#include<limits.h>
using namespace std;
void bellmn(int edge[][3],int m,int n,int dist[],int src)
{
    for(int i=0;i<n;i++)
    {
      dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a=edge[j][0];
            int b=edge[j][1];
            int wt=edge[j][2];
            if(dist[a]!=INT_MAX && dist[a]+wt<dist[b])
            {
                dist[b]=dist[a]+wt;
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        int a=edge[j][0];
        int b=edge[j][1];
        int wt=edge[j][2];
        if(dist[a]!=INT_MAX && dist[a]+wt<dist[b])
        {
           cout<<"negative cycle ahe "<<endl;
        }
    }
        cout<<"shortest distanc from source:"<<src<<" to all vertices"<<endl;
        for(int i=0;i<n;i++)
        {
          cout<<src<<"---->"<<i<<" ="<<dist[i]<<endl;
        }
}
int main()
{
    int n;
    cout<<"enter no of vertices"<<endl;
    cin>>n;
    int m;
    cout<<"enter no of edges"<<endl;
    cin>>m;
    int dist[n];
    int edge[m][3];
    for(int i=0;i<m;i++)
    {
        cout<<"enter source of "<<"edge:"<<i+1<<endl;
        cin>>edge[i][0];
        cout<<"enter  destination of "<<"edge:"<<i+1<<endl;
        cin>>edge[i][1];
        cout<<"enter weight of "<<"edge:"<<i+1<<endl;
        cin>>edge[i][2];
    }
    int src;
    cout<<"enter source"<<endl;
    cin>>src;
    bellmn(edge,m,n,dist,src);
    return 0;
}