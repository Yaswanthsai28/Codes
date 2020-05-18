//URL : https://www.codechef.com/problems/FIRESC

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector<int>g[1000001];
int vis[1000001] , cc_size;

void dfs(int node)
{
    vis[node]=1;
    cc_size++;
    
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
        int n,m,a,b;
        cin>>n>>m;
        
        for(int i=1;i<=n;i++) g[i].clear() , vis[i]=0;
        
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        int cc=0;
        
        ll res=1;
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                cc_size=0;
                
                dfs(i);
                cc++;
                
                res=(res*cc_size) % mod;
            }
        }
        
        cout<<cc<<" "<<res<<"\n";
    }
}


/* Input :

3
4 2
1 2
2 3
5 3
1 2
2 3
1 3
6 3
1 2
3 4
5 6

Output : 

2 3
3 3
3 8

*/
