//PRIME PATH USING BFS.

//URL : https://www.spoj.com/problems/PPATH/

#include<bits/stdc++.h>
using namespace std;

vector<int>g[10001];
vector<int>primes;

int vis[10001] , dis[10001];

bool isValid(int a, int b)
{
    int c=0;
    
    while(a>0)
    {
        if(a%10 != b%10) c++;
        
        a/=10 , b/=10;
    }
    
    if(c==1) return true;
    else return false;
}

bool isprime(int num)
{
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0) return false;
    }
    return true;
}

void buildgraph()
{
    for(int i=1000;i<=9999;i++)
    {
        if(isprime(i)) primes.push_back(i);
    }
    
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            int a=primes[i];
            int b=primes[j];
            
            if(isValid(a,b)) g[a].push_back(b) , g[b].push_back(a);
        }
    }
}

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        
        for(int child : g[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
                vis[child]=1;
                dis[child]=dis[curr]+1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    buildgraph();
    
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        
        for(int i=1000;i<=9999;i++) vis[i]=0, dis[i]=-1;
        
        bfs(a);
        
        if(dis[b]==-1) cout<<"Impossible"<<"\n";
        else cout<<dis[b]<<"\n";
    }
}

/******************
Input : 
3
1033 8179
1373 8017
1033 1033

Output :
6
7
0
********************/
