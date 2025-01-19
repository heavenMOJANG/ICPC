#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{ll x,y;}m[200010];
ll n,k,a,b;
void solve(){
    cin>>n>>k>>a>>b;
    for(ll i=1;i<=n;++i) cin>>m[i].x>>m[i].y;
    ll csta=1e18,cstb=1e18;
    for(ll i=1;i<=k;++i){
        csta=min(csta,abs(m[a].x-m[i].x)+abs(m[a].y-m[i].y));
        cstb=min(cstb,abs(m[b].x-m[i].x)+abs(m[b].y-m[i].y));
    }
    cout<<min(abs(m[a].x-m[b].x)+abs(m[a].y-m[b].y),csta+cstb)<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
