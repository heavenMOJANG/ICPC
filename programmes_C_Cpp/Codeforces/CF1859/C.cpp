#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n;
void solve(){
    cin>>n;
    ll maxn=0;
    for(ll i=1;i<=n;++i){
        ll idx=n,sum=0,res=0;
        for(ll j=1;j<i;++j) sum+=j*j,res=max(res,j*j);
        for(ll j=i;j<=n;++j) sum+=j*idx,res=max(res,j*idx),idx--;
        maxn=max(maxn,sum-res);
    }
    cout<<maxn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
