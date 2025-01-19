#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n;cin>>n;
	vector<vector<ll>>a(n+1);
	vector<ll>vis(n+1);
    vector<map<ll,ll>>mpp(n+1);
	map<ll,ll>mp;
	set<ll>s;
	for(ll i=1,k;i<=n;++i){
		cin>>k;
		for(ll j=1,x;j<=k;++j) {
			cin>>x;
			mp[x]=mpp[i][x]=1;
			a[i].push_back(x);
			s.insert(x);
		}
	}
	ll maxn=0;
	for(ll k=1;k<=50;++k)
        if(mp[k]){
		    set<ll>tmp;
		    for(ll i=1;i<=n;++i) if(!mpp[i][k]) for(auto x:a[i]) tmp.insert(x);
            maxn=max(maxn,(ll)tmp.size());
	    }
	cout<<maxn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
