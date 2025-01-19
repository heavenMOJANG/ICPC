#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,q,tag[100010],f[100010],dfn[100010],pa[100010],tim;
ll findSet(ll u){
    if(tag[u]) return u;
	else if(dfn[u]==tim) return pa[u];
	pa[u]=tim;
	return pa[u]=findSet(f[u]);
}
void update(ll u){
    if(!tag[u]) tag[u]=1,tim++;
    return;
}
void solve(){
    cin>>n>>q;
    for(ll i=1,u,v;i<n;++i) cin>>u>>v,f[v]=u;
    update(1);
    fill(dfn+1,dfn+1+n,1);
    fill(pa+1,pa+1+n,1);
    for(ll i=1,u;i<=q;++i){
        string op;
        cin>>op>>u;
        switch(op[0]){
            case 'C':update(u);break;
            case 'Q':cout<<findSet(u)<<"\n";break;
        }
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
