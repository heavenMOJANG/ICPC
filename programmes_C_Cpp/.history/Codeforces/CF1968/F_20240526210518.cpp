#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    map<int,vector<int>>mp;
    mp[0].emplace_back(0);
    for(int i=1;i<=n;++i) cin>>a[i],a[i]^=a[i-1],mp[a[i]].emplace_back(i);
    while(q--){
        int l,r;cin>>l>>r;
        int x=a[r]^a[l-1];
        if(x==0){cout<<"YES\n";continue;}
        auto i=lower_bound(mp[a[r]].begin(),mp[a[r]].end(),l);
        if(i==mp[a[r]].end()||*i>=r){cout<<"NO\n";continue;}
        auto j=lowuppr_bound(mp[a[l-1]].begin(),mp[a[l-1]].end(),*i);
        if(j==mp[a[l-1]].end()){cout<<"NO\n";continue;}
        cout<<(*i<*j&&*j<r?"YES\n":"NO\n");
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}