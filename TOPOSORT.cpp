//Using Topological Sort - Khan's Algorithm

//URL : https://www.spoj.com/problems/TOPOSORT/

#include<bits/stdc++.h>
using namespace std;

vector<int>g[100001];
int indegree[100001];

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
        g[a].push_back(b);
        indegree[b]++;
    }
    
    priority_queue<int,vector<int>,greater<int>>q;
    vector<int>res;
    
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    
    while(!q.empty())
    {
        int curr=q.top();
        res.push_back(curr);
        q.pop();
        
        for(int child : g[curr])
        {
            indegree[child]--;
            if(indegree[child]==0) q.push(child);
        }
    }
    
    if(res.size()==n)
    {
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    }
    else cout<<"Sandro fails."<<"\n";
}

/****************************

1.INPUT : 
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6
OUTPUT :
1 4 3 5 7 8 2 6 

2.INPUT :
2 2
1 2
2 1
OUTPUT :
Sandro fails.

***************************/
