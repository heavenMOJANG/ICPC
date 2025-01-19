#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{ll id,sum;}a[5010];
ll n,m,cnt,res;
int cmp(node x,node y){return x.sum==y.sum?x.id<y.id:x.sum>y.sum;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    m=floor(m*1.5);
    for(ll i=1;i<=n;++i) cin>>a[i].id>>a[i].sum;
    sort(a+1,a+1+n,cmp);
    res=a[m].sum;
    for(ll i=1;i<=n;++i) if(a[i].sum>=res) cnt++;
    cout<<res<<" "<<cnt<<"\n";
    for(ll i=1;i<=cnt;++i) cout<<a[i].id<<" "<<a[i].sum<<"\n";
    return 0;
}