#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=1000010;
struct Node{ll a,b,c;}t[N];
ll n,m,p[N],d[N],res,s[N];
void ins(ll l,ll r,ll c){d[l]+=c,d[r+1]-=c;}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=m;++i) cin>>p[i];
    for(ll i=1;i<n;++i) cin>>t[i].a>>t[i].b>>t[i].c;
    for(ll i=1;i<m;++i)
        if(p[i]<=p[i+1]) ins(p[i],p[i+1]-1,1);
        else ins(p[i+1],p[i]-1,1);
    for(ll i=1;i<n;++i) s[i]=s[i-1]+d[i],res+=min(t[i].a*s[i],t[i].c+t[i].b*s[i]);
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}