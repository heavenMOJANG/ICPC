#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,f[500010],pre[500010],res,idx,flag;
string s;
map<ll,ll>mp;
ll findSet(ll x){
    if(x==f[x]) return x;
    ll tmp=f[x];
    f[x]=findSet(f[x]);
    pre[x]^=pre[tmp];
    return f[x];
}
ll merge(ll x,ll y,ll z){
    ll fx=findSet(x),fy=findSet(y);
    if(fx==fy&&pre[x]^pre[y]==z) return 1;
    else if(fx==fy) return 0;
    f[fx]=fy;
    pre[fx]=pre[x]^pre[y]^z;
    return 1;
}
void solve(){
    cin>>n>>m;
    for(ll i=0;i<=100000;++i) f[i]=i;
    for(ll i=1,l,r;i<=m;++i){
        cin>>l>>r>>s;
        if(flag) continue;
        l--;
        ll w=(s=="even"?0:1);
        if(!mp[l]) mp[l]=++idx;
        if(!mp[r]) mp[r]=++idx;
        if(!merge(mp[l],mp[r],w)) res=i-1,flag=1;
        else if(i==m) res=m;
    }
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}