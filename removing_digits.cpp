#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int temp = i;
        while(temp > 0)
        {
            if(temp%10 != 0)
                dp[i] = min(dp[i], dp[i-(temp%10)]+1);
            temp/= 10;
        }
    }
    cout<<dp[n];
}