#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,k;cin>>n;
    vector<ll>a(n);
    priority_queue<pair<ll,ll>>q;
    for(ll i=0;i<n;++i) cin>>a[i],q.push({-a[i],i+1});
    cin>>k;
    vector<ll>s(n+10);
    ll lp=0,last=0;
    while(!q.empty()&&k){
        auto [x,p]=q.top();q.pop();
        if(p<=lp)continue;
        x=-x;
        ll tmp=k/(x-last);
        if(lp) tmp=min(tmp,-s[lp+1]);
        k-=tmp*(x-last);
        s[lp+1]+=tmp;
        s[p+1]-=tmp;
        lp=p;
        last=x;
    }
    for(ll i=1;i<=n;++i) s[i]+=s[i-1],cout<<s[i]<<" \n"[i==n];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
