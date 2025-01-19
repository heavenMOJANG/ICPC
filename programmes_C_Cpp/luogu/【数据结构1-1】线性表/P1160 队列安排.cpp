#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Node{ll l,r,f;}a[1000010];
ll n,m;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=2;i<=n;++i){
        ll k,p;cin>>k>>p;
        if(p){
            a[i].l=k;
            a[i].r=a[k].r;
            a[a[k].r].l=i;
            a[k].r=i;
        }
        else{
            a[i].r=k;
            a[i].l=a[k].l;
            a[a[k].l].r=i;
            a[k].l=i;
        }
    }
    cin>>m;
    for(ll i=1,x;i<=m;++i) cin>>x,a[x].f=1;
    for(ll i=a[0].r;i;i=a[i].r) if(!a[i].f) cout<<i<<" ";
    return 0;
}