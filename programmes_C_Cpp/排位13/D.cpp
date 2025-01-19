#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;
    map<int,vector<int>>mp;
    while(cin>>n>>m){
        mp.clear();
        for(int i=0,x;i<n;++i) cin>>x,mp[x].push_back(i);
        for(int i=0;i<m;++i){
            int k,v;cin>>k>>v;
            cout<<(mp[v].size()<k?0:mp[v][k-1]+1)<<"\n";
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
