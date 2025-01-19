#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s[n+1];
    for(int i=1;i<=n;++i) cin>>s[i],s[i]=" "+s[i];
    int res=0;
    vector ld(n+2,vector(n+2,0)),rd=ld,v=ld,sum=ld;
    for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(ld[i][j]){
				sum[i][j]^=1;
				ld[i+1][j-1]^=1;
				v[i+1][j]^=1;
			}
			if(v[i][j]){
				sum[i][j]^=1;
				v[i+1][j]^=1;
			}
			if(rd[i][j]) {
				sum[i][j]^=1;
				rd[i+1][j+1]^=1;
				v[i+1][j]^=1;
			}
			int num=s[i][j]-'0';
			if(num^sum[i][j]){
				res++;
				ld[i+1][j-1]^=1;
				v[i+1][j] ^= 1;
				rd[i+1][j+1]^=1;
			}
		}
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
