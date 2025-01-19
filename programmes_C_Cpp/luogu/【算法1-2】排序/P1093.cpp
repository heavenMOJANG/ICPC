#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{ll id,ch,ma,en,sum;}a[310];
ll n;
int cmp(node x,node y){return x.sum==y.sum?x.ch==y.ch?x.id<y.id:x.ch>y.ch:x.sum>y.sum;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].ch>>a[i].ma>>a[i].en,a[i].id=i,a[i].sum=a[i].ch+a[i].ma+a[i].en;
    sort(a+1,a+1+n,cmp);
    for(ll i=1;i<=5;++i) cout<<a[i].id<<" "<<a[i].sum<<"\n";
    return 0;
}