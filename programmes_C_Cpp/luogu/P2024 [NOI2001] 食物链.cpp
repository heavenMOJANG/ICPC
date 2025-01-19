#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,k,f[50010],d[50010],cnt;
ll find_set(ll x){
    ll fx=f[x];
    if(x!=f[x]){
        f[x]=find_set(f[x]);
        d[x]=(d[x]+d[fx])%3;
    }
    return f[x];
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;++i) f[i]=i;
    while(k--){
        ll c,x,y;cin>>c>>x>>y;
        if(x>n||y>n||(c==2&&x==y)) cnt++;
        else{
            ll fx=find_set(x),fy=find_set(y);
            if(fx==fy){if((d[x]-d[y]+3)%3!=c-1) cnt++;}
            else{f[fx]=fy;d[fx]=(d[y]-d[x]+3+c-1)%3;}
        }
    }
    cout<<cnt;
    return 0;
}