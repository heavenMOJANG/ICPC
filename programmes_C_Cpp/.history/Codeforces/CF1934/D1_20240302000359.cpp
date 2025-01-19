#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    int a=n^m,k=log2(a)+1;
    vector<int>v;
    for(int i=k-1;i;--i){
        if(((1ll<<i)&a==1)&&((1ll<<i)&n==0)){cout<<"-1\n";return;}
        else v.push_back(1ll<<i);
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();++i) cout<<v[i]<<" \n"[i==v.size()-1]; 
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
