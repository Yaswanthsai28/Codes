#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    // cout<<n<<endl;
    int a[n]={0},j=0;
    for(int i=0;i<n;i+=2)
    {
        a[j]=(s[i]-'0');
        j++;
    }
    // for(int i=0;i<j;i++) cout<<a[i]<<" ";
    // cout<<endl;
    sort(a,a+j);
    for(int i=0;i<j-1;i++) cout<<a[i]<<"+";
    cout<<a[j-1];
}

//Input : 1+3+2 --> Output : 1+2+3
