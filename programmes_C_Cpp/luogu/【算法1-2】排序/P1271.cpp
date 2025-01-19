#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{ll id,sum;}a[1010];
ll n,m,x,h[1010],idx;
int cmp(node x,node y){return x.id<y.id;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i) cin>>x,h[x]++;
    for(ll i=1;i<=n;++i) if(h[i]) a[++idx]={i,h[i]};
    sort(a+1,a+1+idx,cmp);
    for(ll i=1;i<=idx;++i){
        for(ll j=1;j<=a[i].sum;++j) cout<<a[i].id<<" ";
    }
    return 0;
}