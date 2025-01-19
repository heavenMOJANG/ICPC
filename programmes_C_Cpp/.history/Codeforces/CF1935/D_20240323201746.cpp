#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,c;cin>>n>>c;
	vector<int>a(n+1); 
	for(int i=1;i<=n;++i) cin>>a[i];
	int sum=(c+2)*(c+1)/2;	
	int cnt[2]={};
	for(int i=1;i<=n;++i){
		cnt[a[i]%2]++;
		sum-=a[i]/2+1;
		sum-=c-a[i]+1;
	}
	sum+=cnt[0]*(cnt[0]+1)/2+cnt[1]*(cnt[1]+1)/2;
	cout<<sum<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
