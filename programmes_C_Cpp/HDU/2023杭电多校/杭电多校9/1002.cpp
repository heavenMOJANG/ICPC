#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n;
map<ll,ll>mp;
ll dfs(ll x){
    if(mp.find(x)!=mp.end()) return mp[x];
    ll res=0;
    if(x/2>0) res=x%2+dfs(x/2)+1;
    if(x/3>0) res=min(res,x%3+dfs(x/3)+1);
    return mp[x]=res;
}
void solve(){
    ll step=0;
    cin>>n;
    mp.clear();
    mp[1]=0;mp[2]=1;mp[3]=1;
    cout<<dfs(n)<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
