#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[30],cnt;
int check(ll x){
    if(x<2) return 0;
    for(ll i=2;i<=sqrt(x);++i) if(x%i==0) return 0;
    return 1;
}
void dfs(ll x,ll num,ll sum){
    if(num==k){if(check(sum)) cnt++;return;}
    for(ll i=x;i<n;++i) dfs(i+1,num+1,sum+a[i]);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=0;i<n;++i) cin>>a[i];
    dfs(0,0,0);
    cout<<cnt;
    return 0;
}