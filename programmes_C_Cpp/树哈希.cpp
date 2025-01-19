#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
constexpr ll inf=0x7fffffff;
const ull mask=chrono::steady_clock::now().time_since_epoch().count();
ll n;
ull h[1000010];
vector<ll>e[1000010];
set<ull>t;
ull shift(ull x){
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}
void getHash(ll x,ll p){
    h[x]=1;
    for(ll i:e[x]){
        if(i==p) continue;
        getHash(i,x);
        h[x]+=shift(h[i]);
    }
    t.insert(h[x]);
}
void solve(){
    cin>>n;
    for(ll i=1,u,v;i<n;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    getHash(1,0);
    cout<<t.size();
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
