#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>p(n+1),pos(n+1);
    for(int i=1;i<=n;++i) cin>>p[i];
    for(int i=1;i<=n;++i) pos[p[i]]=i;
    if(x==1){cout<<"1\n1 "<<pos[1]<<"\n";return;}
    vector<array<int,4>>op;
    int l=1,r=n+1;
    while(l+1<r){
        int m=l+r>>1;
        if(p[m]<=x) l=m;
        else r=m;
    }
    for(auto [cl,cr,m,pm]:op) cout<<cl<<" "<<cr<<" "<<m<<" "<<pm<<"\n";
    if(p[l]==x) cout<<"0\n";
    else cout<<"1\n"<<pos[x]<<" "<<l<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
