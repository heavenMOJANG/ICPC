#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
const ll mod=666623333;
ll l,r,prime[1000010],idx,vis[1000010],phi[1000010],last[1000010];
void euler(ll x){
    vis[1]=1;
    for(ll i=2;i<=x;++i){
        if(!vis[i]) prime[++idx]=i;
        for(ll j=1;j<=idx&&i*prime[j]<=x;++j){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>l>>r;
    euler(1000000);
    for(ll i=l;i<=r;++i){
        ll cur=i-l;
        phi[cur]=last[cur]=i;
    }
    for(ll i=1;i<=idx&&prime[i]*prime[i]<=r;++i){
        ll p=prime[i];
        for(ll j=l/p*p+((l%p)?p:0);j<=r;j+=p){
            ll cur=j-l;
            phi[cur]/=p;
            phi[cur]*=p-1;
            while (last[cur]%p==0) last[cur]/=p;
        }
    }
    for(ll i=l;i<=r;++i){
        ll cur=i-l;
        if(last[cur]>1){
            phi[cur]/=last[cur];
            phi[cur]*=(last[cur]-1);
        }
    }   
    ll ans=0;
    for(ll i=l;i<=r;++i) {
        ll cur=i-l;
        ans=(ans+(i-phi[cur])%mod)%mod;
    }
    cout<<ans;
    return 0;
}