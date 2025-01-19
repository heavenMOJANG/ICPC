#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,cur,worklist[410],workmac[25][25],worktime[25][25],lasttime[25],timeline[25][10010],step[25],maxn; 
ll check(ll start,ll end,ll num){    
    for(ll i=start;i<=end;++i) if(timeline[num][i]==1) return 0;
    return 1;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(ll i=1;i<=n*m;++i) cin>>worklist[i];
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>workmac[i][j];
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>worktime[i][j];
    ll mac,costtime;
    for(ll i=1;i<=n*m;++i){
        cur=worklist[i]; 
        step[cur]++;
        mac=workmac[cur][step[cur]];
        costtime=worktime[cur][step[cur]];
        for(ll k=lasttime[cur]+1;;++k)
            if(check(k,k+costtime-1,mac)){
                for(ll j=k;j<=k+costtime-1;++j) timeline[mac][j]=1;
                lasttime[cur]=k+costtime-1;
                break;
            }
    }
    for(ll i=1;i<=n;++i) maxn=max(maxn,lasttime[i]);
    cout<<maxn;
    return 0;
}