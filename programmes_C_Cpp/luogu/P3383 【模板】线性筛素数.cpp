#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,prime[100010],vis[100010],idx;
void Euler_Sieve(ll x){
    memset(vis,1,sizeof(vis));
    vis[1]=0;
    for(ll i=2;i<=x;++i){
        if(vis[i]) prime[idx++]=i;
        for(ll j=0;j<idx&&i*prime[j]<=x;++j){
            vis[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    Euler_Sieve(n);
    return 0;
}