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
struct line{
    ll l,r;
    bool operator<(const line&x)const{return r<x.r;}
}a[1000010];
ll n,res,cur;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;++i) if(a[i].l>=cur) cur=a[i].r,res++;
    cout<<res;
    return 0;
}