#include<bits/stdc++.h>
using namespace std;

vector<int>g[101];
int vis[101] , in[101] , low[101];
int timer;

void dfs(int node,int par)
{
    vis[node]=1;
    in[node] = low[node] = timer;
    timer++;

    for(int child : g[node])
    {
        if(child==par) continue;

        if(vis[child]==1)
        {
            // presence of back edge
            low[node] = min(low[node] , in[child]);
        }
        else
        {
            // presence of forward edge

            dfs(child,node);

            if(low[child] > in[node]) cout<<node<<" - "<<child<<" is a bridge"<<"\n";

            low[node] = min(low[node] , low[child]);
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,a,b;

    cin>>n>>m;

    while(m--)
    {
        cin>>a>>b;
        g[a].push_back(b) , g[b].push_back(a);
    }

    dfs(1 , -1);

    return 0;
}