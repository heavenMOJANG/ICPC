#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
int n,q,k,prime[100000010],vis[100000010],idx;
void Euler_Sieve(ll x){
    memset(vis,1,sizeof(vis));
    for(int i=2;i<=x;++i){
        if(vis[i]) prime[idx++]=i;
        for(int j=0;j<idx&&i*prime[j]<=n;++j){
            vis[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    Euler_Sieve(n);
    for(int i=1;i<=q;++i) cin>>k,cout<<prime[k-1]<<"\n";
    return 0;
}