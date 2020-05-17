//SPOJ Bipartite graph test

//URL : https://www.spoj.com/problems/BUGLIFE/

#include<bits/stdc++.h>
using namespace std;

vector<int>g[20001];
int vis[20001] , col[20001];

bool dfs(int node,int c)
{
    vis[node]=1;
    col[node]=c;
    
    for(int child : g[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child, c^1)==false) return false;
        }
        else if(col[node]==col[child]) return false;
    }
    
    return true;
}

int main()
{
    int t,n,m,a,b;
    cin>>t;
    
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n>>m;
        
        for(int i=1;i<=n;i++) g[i].clear() , vis[i]=0;
        
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        bool flag=true;
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                bool res = dfs(i,0);
                
                if(res==false)
                {
                    flag=false;
                    break;
                }
            }
        }
        
        cout<<"Scenario #"<<tc<<":"<<"\n";
        
        if(flag==true) cout<<"No suspicious bugs found!"<<"\n";
        
        else cout<<"Suspicious bugs found!"<<"\n";
    }
}
