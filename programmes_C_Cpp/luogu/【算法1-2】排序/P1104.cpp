#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{string s;ll id,y,m,d;}a[110];
ll n;
int cmp(node x,node y){return x.y==y.y?x.m==y.m?x.d==y.d?x.id>y.id:x.d<y.d:x.m<y.m:x.y<y.y;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].s>>a[i].y>>a[i].m>>a[i].d,a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(ll i=1;i<=n;++i) cout<<a[i].s<<"\n";
    return 0;
}