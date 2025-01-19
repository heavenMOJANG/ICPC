#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n),x(n);
    vector<int>id(n);
    for(int i=0;i<n;++i) cin>>a[i],id[i]=i;
    for(int i=0;i<n;++i) cin>>x[i],x[i]=abs(x[i]);
    sort(id.begin(),id.end(),[&](int a,int b){return x[a]<x[b];});
    int sum=0,flag=1;
    for(auto y:id){
        sum+=a[y];
        if(1ll*x[y]*k<sum){flag=0;break;}
    }
    cout<<(flag?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
