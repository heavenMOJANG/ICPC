#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int x;cin>>x;
	vector<int>ans={x};
	int tmp=x&(-x);
	while(x!=tmp) {
		x-=tmp;
		ans.push_back(x);
		tmp=x&(-x);
	}
	while(x!=1){
		x-=x/2;
		ans.push_back(x);
	}
	cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<" \n"[i==ans.size()-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
