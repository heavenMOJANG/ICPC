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
struct Node{
    ll val,sum;
    bool operator<(const Node&x)const{return val<x.val;}
}a[2000010];
ll n,m,res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i) cin>>a[i].val>>a[i].sum;
    sort(a+1,a+1+m);
    for(ll i=1;i<=m;++i)
        if(a[i].sum>n){res+=n*a[i].val;break;}
        else res+=a[i].val*a[i].sum,n-=a[i].sum;
    cout<<res;
    return 0;
}