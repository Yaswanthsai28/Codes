//Using Articulation points concept

//URL : https://www.spoj.com/problems/SUBMERGE/

#include<bits/stdc++.h>
using namespace std;

vector<int>g[100001];
int vis[100001] , in[100001] , low[100001];
int timer;
set<int>ans;

void dfs(int node,int par)
{
    vis[node]=1;
    in[node] = low[node] = timer;
    timer++;
    int childern=0;

    for(int child : g[node])
    {
        if(child==par) continue;

        if(vis[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            childern++;
            

            if(in[node] <= low[child] && par!=-1) ans.insert(node);

            low[node]=min(low[node],low[child]);
        }
        
    }
    if(par==-1 && childern>1) ans.insert(node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,a,b;

    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0) break;

        for(int i=1;i<=n;i++) g[i].clear() , vis[i]=0;
        ans.clear();
        timer=0;

        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            g[a].push_back(b) , g[b].push_back(a);
        }

        for(int i=1;i<=n;i++) 
        {
            if(vis[i]==0) dfs(i , -1);
        }
        cout<<ans.size()<<"\n";
    }
}
