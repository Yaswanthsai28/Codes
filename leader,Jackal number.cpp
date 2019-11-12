#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,max=0,sum=0;
        scanf("%d",&n);
        int a[n];
        for(int j=0;j<n;j++) 
        {
            scanf("%d",&a[j]);
        }
        max=a[n-1];
        sum+=max;
        for(int j=n-2;j>=0;j--)
        {
            if(max<a[j]) 
            {
                max=a[j];
                sum+=max;
            }
        }
        cout<<sum;
}
