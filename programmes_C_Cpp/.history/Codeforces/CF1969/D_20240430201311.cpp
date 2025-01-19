#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n),b(n),idx(n,0);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    sort(idx.begin(),idx.end(),[&](int x,int y){return b[x]!=b[y]?b[x]>b[y]:a[x]<a[y];});
    int s1=0,s2=0,ans=0;
    set<pair<int,int>>s;
    for(int i=0;i<k;++i){
        s.insert({a[idx[i]],idx[i]});
        s1+=a[idx[i]];
    }
    for(int i=k;i<n;++i) if(b[idx[i]]>a[idx[i]]) s2+=b[idx[i]]-a[idx[i]];
    for(int i=k;i<n;++i){
        ans=max(ans,s2-s1);
        if(b[idx[i]]>a[idx[i]]) s2-=b[idx[i]]-a[idx[i]];
        s.insert({a[idx[i]],idx[i]});
        s1+=a[idx[i]];
        s1-=prev(s.end())->first;
        s.erase(prev(s.end()));
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}