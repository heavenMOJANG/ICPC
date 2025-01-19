#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,x;cin>>n>>m>>x;
	vector<vector<int>>dp(m+1,vector<int>(n+1,0));
	dp[0][x-1]=1;
	for(int i=1,len;i<=m;i++){
	    char op;
		cin>>len>>op;
		for(int j=0;j<n;j++){
			if(dp[i-1][j]){
				if(op=='0') dp[i][(j+len)%n] |= dp[i-1][j];
				else if(op=='1') dp[i][(j-len+n)%n] |= dp[i-1][j];
				else{
					dp[i][(j+len)%n] |= dp[i-1][j];
					dp[i][(j-len+n)%n] |= dp[i-1][j];
				}
			}
		}
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(dp[m][i]) ans.push_back(i);
	}
	cout<< (int)ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" \n"[i==ans.size()-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
