//Finding Minimum Spanning Tree

// Using DSU - PATH COMPRESSION

#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int a,b,w;
};

edge g[100001];
int par[100001];

bool comp(edge a,edge b)
{
    if(a.w < b.w) return true;

    return false;
}

int find(int a)
{
    if(par[a]<0) return a;

    return par[a]=find(par[a]);
}

void mingle(int a,int b)
{
    par[a]+=par[b];

    par[b]=a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,a,b;
    cin>>n>>m;

    for(int i=1;i<=n;i++) par[i]=-1;

    for(int i=0;i<m;i++)
    {
        cin>>g[i].a>>g[i].b>>g[i].w;
    }

    sort(g,g+m,comp);

    int sum=0;

    for(int i=0;i<m;i++)
    {
        a=find(g[i].a);
        b=find(g[i].b);

        if(a!=b)
        {
            sum+=g[i].w;
            mingle(a,b);
        }
    }

    cout<<sum<<"\n";
}

/**************************

Input :
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
Output :
19

*****************************/
