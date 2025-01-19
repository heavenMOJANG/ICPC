#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,m,op,a[500010],tree[500010];
void update(ll x,ll d){while(x<=n) tree[x]+=d,x+=lowbit(x);}
ll sum(ll x){ll res=0;while(x>0) res+=tree[x],x-=lowbit(x);return res;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i){cin>>a[i],update(i,a[i]-a[i-1]);}
    for(ll i=1;i<=m;++i){
        cin>>op;
        if(op==1){
            ll x,y,k;cin>>x>>y>>k;
            update(x,k);
            update(y+1,-k);
        }
        else{
            ll x;cin>>x;
            cout<<sum(x)<<"\n";
        }
    }
    return 0;
}