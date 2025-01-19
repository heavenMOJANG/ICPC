#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int prime[100010],vis[100010],idx;
void Euler_Sieve(ll x){
    memset(vis,1,sizeof(vis));
    vis[1]=0;
    for(ll i=2;i<=x;++i){
        if(vis[i]) prime[idx++]=i;
        for(ll j=0;j<idx&&i*prime[j]<=x;++j){
            vis[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
}
void solve() {
    int n; cin >> n;
    for ()
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}