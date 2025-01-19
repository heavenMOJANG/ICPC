#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5e5+10;
vector<int>cnt[N],f[N],v1[N],v2[N];
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];

}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<N;++i)
        for(int j=1;j<N;j+=i) f[j].emplace_back(i);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}