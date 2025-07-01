#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{ll val,num;}a[500010];
ll n;
ll cmp(Node x,Node y){return x.num==y.num?x.val<y.val:x.num>y.num;}
void solve(){
    cin>>n;
    ll idx=0,minn=LLONG_MAX;
    map<ll,ll>mp;
    for(ll i=1,x;i<=n;++i) cin>>x,mp[x]++,minn=min(minn,x);
    for(auto it=mp.begin();it!=mp.end();++it) a[++idx]={it->first,it->second};
    sort(a+1,a+1+idx,cmp);
    if(a[1].val!=minn) cout<<"NO\n";
    else cout<<"YES\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
