#include<bits/stdc++.h>
using namespace std;
int main()
{   int mod=1e9+7;
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    
    vector<int>curr(n+1,0);
    vector<int>prev(n+1,0);
    if(grid[n-1][n-1]!='*') curr[n-1]=1;
    for(int i=n-1;i>=0;i--)
    {   vector<int>temp(n+1,0);
        for(int j=n-1;j>=0;j--)
        {
            if(grid[i][j]=='*')
            curr[j]=0;
            else if(i!=n-1 || j!=n-1)
            curr[j]=(prev[j]%mod+curr[j+1]%mod)%mod;
        }
        prev=curr;
        curr=temp;
    }
    cout<<prev[0]%mod;
}