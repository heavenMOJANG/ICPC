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
struct Node{ll id,t;}a[1010];
ll n,sum;
ll cmp(Node x,Node y){return x.t==y.t?x.id<y.id:x.t<y.t;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].t,a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(ll i=1;i<=n;++i) sum+=a[i].t*(n-i);
    for(ll i=1;i<=n;++i) cout<<a[i].id<<" ";cout<<"\n";
    cout<<fixed<<setprecision(2)<<(sum*1.0)/(n*1.0);
    return 0;
}