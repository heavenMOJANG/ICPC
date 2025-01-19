#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    int maxn=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mp[a[i]]++;
        maxn=max(maxn,a[i]);
    }
    if(mp[maxn]&1){cout<<"YES\n";return;}
    n-=mp[maxn];
    if(n&1) cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}