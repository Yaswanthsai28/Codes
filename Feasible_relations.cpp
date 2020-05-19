//Feasible relations (Hackerearth)

//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/description/


#include<bits/stdc++.h>
using namespace std;

vector<int>g[1000001];
int vis[1000001] , cc[1000001];
int curr_cc;

void dfs(int node)
{
    vis[node]=1;
    cc[node]=curr_cc;
    
    for(int child : g[node])
    {
        if(vis[child]==0) dfs(child);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k,a,b;
        cin>>n>>k;

        curr_cc=0;

        string op;
        
        for(int i=1;i<=n;i++) g[i].clear() , vis[i]=0 , cc[i]=0;
        
        vector<pair<int,int>>edges;
        
        for(int i=1;i<=k;i++)
        {
            cin>>a>>op>>b;
            
            if(op == "=") g[a].push_back(b) , g[b].push_back(a);
            
            else edges.push_back({a,b});
        }
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                curr_cc++;
                dfs(i);
            }
        }
        
        bool flag=true;
        
        for(int i=0;i<edges.size();i++)
        {
            a=edges[i].first;
            b=edges[i].second;
            
            if(cc[a]==cc[b])
            {
                flag=false;
                break;
            }
        }
        
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}

/**********************************
Input :
2
2 2
1 = 2
1 != 2
3 2
1 = 2
2 != 3

Output:
NO
YES

**********************************/
