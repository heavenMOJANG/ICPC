#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define pll pair<long long,long long> 
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[200010],d[200010],l[200010],r[200010],res[200010];
vector<pll>tag[200010];
ll check(ll x){
    priority_queue<pll,vector<pll>,greater<pll>>pq;
	for(ll i=1;i<=n;++i) res[i]=a[i];
	for(ll i=1;i<=n;++i){
		for(auto [tp,id]:tag[i])
		if(tp<0){
            if(res[id]) return 0;
		}
        else
            if(res[id]) pq.push({r[id],id});
		ll cur=0; 
        while(!pq.empty()){
			auto [R,ID]=pq.top();pq.pop();
			ll dlt=min(x-cur,res[ID]); 
            cur+=dlt; 
            res[ID]-=dlt;
			if(res[ID]) pq.push({R,ID});
			if(cur==x) break;
		}
	}
	return pq.empty();
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<=n;++i){
        cin>>d[i];
        l[i]=max(1ll,i-d[i]);
        r[i]=min(n,i+d[i]);
		tag[l[i]].push_back({1,i});
        tag[r[i]+1].push_back({-1,i});
    }
    for(ll i=1;i<=n;++i) sort(tag[i].begin(),tag[i].end());
	ll l=0,r=1e9,res; 
    while(l<=r){
        ll mid=l+r>>1;
	    if(check(mid)) res=mid,r=mid-1; 
        else l=mid+1;
    }
	cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
