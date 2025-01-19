#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    vector<ll>a(n),b(m);
    ll suma=0,sumb=0;
    for(ll i=0;i<n;++i) cin>>a[i],suma+=a[i];
    for(ll i=0;i<m;++i) cin>>b[i],sumb+=b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(k&1) cout<<max(suma,suma-a[0]+b[m-1])<<"\n";
    else{
        ll minn=b[0],maxn=a[n-1];
        if(a[0]<b[m-1]){
            minn=min(minn,a[0]);
            maxn=max(maxn,b[m-1]);
            suma+=b[m-1]-a[0];
        }
        suma+=minn-maxn;
        cout<<suma<<"\n";
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
