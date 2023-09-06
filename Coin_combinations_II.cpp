#include<bits/stdc++.h>
using namespace std;
 
const long int MOD =1e9 + 7;
 
int main() {
	int n, x;
	cin>>n>>x;
	int coins[n];
	for(int i=0;i<n;i++) cin>>coins[i];
	
	vector<int>dp(x+1,0);
	dp[0]=1;
	for(int j=0;j<n;j++)
	{ 
	 int temp=coins[j];
	 for(int i=1;i<=x;i++)
	 {  if(i-temp>=0)
	    dp[i]=dp[i]+dp[i-temp];
	    dp[i]=dp[i]%MOD;
	 }
	}
	cout<<dp[x]%MOD;
}