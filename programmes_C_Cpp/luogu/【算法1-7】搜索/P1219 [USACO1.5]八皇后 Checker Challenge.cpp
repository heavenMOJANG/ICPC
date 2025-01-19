#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,q[15],b[1<<15]={1},res,mark;
ll lowbit(ll x){return x&(-x);}
void dfs(ll x,ll row,ll ld,ll rd){
    if(x==n+1){
        res++;
        if(res<=3){for(ll i=1;i<=n;++i) cout<<q[i]+1<<" ";cout<<"\n";}
        return;
    }
    ll pos=(row|ld|rd)^mark;
    while(pos){
        ll p=lowbit(pos);
        q[x]=b[p];
        dfs(x+1,row|p,(ld|p)>>1,((rd|p)<<1)&mark);
        pos-=p;
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    mark=(1<<n)-1;
    for(ll i=1;i<=n;++i) b[1<<i]=i;
    dfs(1,0,0,0);
    cout<<res;
    return 0;
}