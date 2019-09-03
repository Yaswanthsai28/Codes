#include <iostream>
using namespace std;
int fib(int n,int m[100]);
int main() {
    int n,m[100],a;
    cin>>n;
    for(int i=0;i<n;i++)
    m[i]=0;
    a=fib(n,m);
    cout<<a;
}
int fib(int n,int m[100])
{
    int c;
    if(m[n-1]!=0)
    {
    return m[n-1];}
    if(n==1 || n==2)
    {return 1;}
    else 
    {c=fib(n-1,m)+fib(n-2,m);
      m[n-1]=c;
      return c;}
}
	