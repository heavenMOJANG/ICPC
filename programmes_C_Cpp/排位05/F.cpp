#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    int maxn=-inf;
    deque<int>dq;
	for(int i=0,x;i<n;++i){
		cin>>x;
		if(!dq.empty()) maxn=max(maxn,dq.front()-x);
		while(!dq.empty()&&dq.back()<=x) dq.pop_back();
		dq.push_back(x);
	}
    cout<<maxn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
