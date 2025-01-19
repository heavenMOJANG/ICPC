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
ll n,m,a[1000010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1,x;i<=m;++i){
        cin>>x;
        ll p=lower_bound(a+1,a+1+n,x)-a;
        if(a[p]==x) cout<<p<<" ";
        else cout<<"-1 ";
    }
    return 0;
}