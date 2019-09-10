#include<iostream>
using namespace std;
void dijkstra(int g[100][100],int n,int s);
int main()
{
    int n,i,j,s;
    cout<<"enter no of vertices:";
    cin>>n;
    int g[100][100];
    cout<<"enter the cost matx:";
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    cin>>g[i][j];
    if(g[i][j]==0)
    g[i][j]=500;
    }
    }
    cout<<"enter source vertex:";
    cin>>s;
    dijkstra(g,n,s);
}
void dijkstra(int g[100][100],int n,int s)
{
    int dist[100],p[100],v[100],c,min,nxt,i,j,d,k;
    for(int i=0;i<n;i++)
    {
      dist[i]=g[s][i];
      p[i]=s;
      v[i]=0;
    }
    dist[s]=0;
    v[s]=1;
    for(c=1;c<n-1;c++)
    {
        min=500;
        for(i=0;i<n;i++)
        if((dist[i]<min)&&(!v[i]))
        {
            min=dist[i];
            nxt=i;
        }
        v[nxt]=1;
        for(i=0;i<n;i++)
        if(!v[i]&&(min+g[nxt][i]<dist[i]))
        {
            dist[i]=min+g[nxt][i];
            p[i]=nxt;
        }
    }
    cout<<"enter the destination vertex:";
    cin>>d;
    cout<<"total distance:"<<dist[d]<<endl;
    cout<<"path followed:"<<d;
    k=d;
    do{
    k=p[k];
    count<<k;
}while(k!=s);
}
    
