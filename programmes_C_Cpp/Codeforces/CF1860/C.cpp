#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[300010];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    if(n==1){cout<<"0\n";return;}
    ll p=1;
    for(ll i=2;i<=n;++i){
        if(a[i]>a[i-1]) break;
        else p=i;
    }
    if(p==n){cout<<"0\n";return;}
    ll minn=a[p],res=1,maxn=a[p+1];
    for(ll i=p+2;i<=n;++i)
        if(minn<a[i]&&a[i]<maxn) res++,maxn=a[i];
        else if(a[i]<minn) minn=a[i];
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
