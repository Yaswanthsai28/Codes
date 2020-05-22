//Using the concept of bridges and DFS tree

//URL : https://codeforces.com/contest/118/problem/E

#include<bits/stdc++.h>
using namespace std;

vector<int>g[100001];
int vis[100001] ,in[100001] , low[100001];
int timer,flag;
vector<pair<int,int>>res;

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
            low[node] = min(low[node] , in[child]);

            if(in[node] > in[child]) res.push_back({node,child});
            
        }
        else
        {
            dfs(child , node);

            if(low[child] > in[node])
            {
                flag=1;
                return;
            }

            res.push_back({node,child});
            low[node]=min(low[node],low[child]);
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

    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b) , g[b].push_back(a);
    }

    dfs(1 , -1);

    if(flag==1) cout<<"0"<<"\n";

    else
    {
        for(int i=0;i<res.size();i++) cout<<res[i].first<<" "<<res[i].second<<"\n";
    }
    
}
