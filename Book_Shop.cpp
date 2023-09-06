#include<bits/stdc++.h>
using namespace std;
//memoization
// int helper(int idx,vector<int>&price,vector<int>&pages,int budget,vector<vector<int>>dp)
// {
//     if(idx==price.size() || budget==0) return 0;
//     if(dp[idx][budget]!=-1) return dp[idx][budget];
//     int take=INT_MIN;
//     if(budget>=price[idx])
//     take=pages[idx]+helper(idx+1,price,pages,budget-price[idx],dp);
//     int nottake=helper(idx+1,price,pages,budget,dp);
//     return dp[idx][budget]=max(take,nottake);
// }
int main()
{
    int n;
    cin>>n;
    int budget;
    cin>>budget;
    vector<int>price(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        price[i]=x;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pages[i]=x;
    }
    vector<vector<int>>dp(n+1,vector<int>(budget+1,INT_MIN));
    
    for(int i=0;i<=budget;i++) dp[n][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    
    for(int i=n-1;i>=0;i--)//idx
    {
        for(int j=1;j<=budget;j++)//budget
        {
            
            if(j>=price[i]) dp[i][j]=pages[i]+dp[i+1][j-price[i]];
            dp[i][j]=max(dp[i][j],dp[i+1][j]);
        }
    }
    cout<<dp[0][budget]<<endl;
    //cout<<helper(0,price,pages,budget,dp);
    
}
