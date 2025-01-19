#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k,d;cin>>n>>m>>k>>d;
	vector<vector<int>>a(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;++i)
		for(int j=0;j<=m-1;++j) cin>>a[i][j];
	vector<vector<int>>dp(n+1,vector<int>(m+1,LLONG_MAX));
	for(int i=1;i<=n;++i){
        int head=0,tail=0;
		vector<int>q(m+10);
		q[0]=0;dp[i][0]=1;
		for(int j=1;j<=m-1;++j){
			while(head<=tail&&j-q[head]-1>d) head++;
			if(head<=tail) dp[i][j]=dp[i][q[head]]+(a[i][j]+1);
			while(head<=tail&&dp[i][q[tail]]>=dp[i][j]) tail--;
			q[++tail]=j;
		}
	}
	vector<int>res;
	for(int i=1;i<=n-k+1;++i){
        int ans=0;
	    for(int j=i;j<=i+k-1;++j) ans+=dp[j][m-1];
		res.push_back(ans);
	}
	sort(res.begin(),res.end());
	cout<<res[0]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
