#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
	for(int i=2;i<=n;++i) cout<<i-1<<" "<<i<<"\n";
	int from=2;
	for(int i=0,x;i<m;++i){
		cin>>x;
		int len=n-from+1;
		if(len==x){cout<<"-1 -1 -1\n";continue;}
		else{
			int to=(n-x+1);
			cout<<"1 "<<from<<" "<<to<<"\n";
			from=to; 
		}
	}
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
