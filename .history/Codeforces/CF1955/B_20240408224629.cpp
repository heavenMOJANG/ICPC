#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,c,d;cin>>n>>c>>d;
    map<int,int>mp;
    vector<int>v(n*n);
    for(int i=0,x;i<n*n;++i) cin>>x,mp[x]=1,v.push_back(x);
    sort(v.begin(),v.end());
    cout<<v[0]<<"\n";
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(mp[v[0]+i*c+j*d]!=1){cout<<"NO\n";return;}
    cout<<"YES\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}