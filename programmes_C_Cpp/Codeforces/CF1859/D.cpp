#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,q;
void solve(){
    cin>>n;
    vector<array<ll,4>>v;
    for(ll i=1,l,r,a,b;i<=n;++i) cin>>l>>r>>a>>b,v.push_back({l,r,a,b});
    sort(v.begin(),v.end());
    cin>>q;
    vector<pair<ll,ll>>query;
    for(ll i=1,x;i<=q;++i) cin>>x,query.push_back({x,i});
    sort(query.begin(),query.end());
    ll r=0,cnt=0;
    vector<ll>ans(q+1);
    for(auto [cur,idx]:query){
        while(cnt<v.size()&&v[cnt][0]<=cur){
			r=max(r,v[cnt][3]);
			cur=max(cur,r);
			cnt++;
		}
		ans[idx]=max(cur,r);
    }
    for(ll i=1;i<=q;++i) cout<<ans[i]<<" ";
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
