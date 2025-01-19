#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,f[100010];
string s;
char c;
ll findSet(ll x){return x==f[x]?x:f[x]=findSet(f[x]);}
void solve(){
    cin>>n>>m>>s;s=" "+s;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1,u,v;i<n;++i){
        cin>>u>>v;
        if(s[u]==s[v]){
            ll fu=findSet(u),fv=findSet(v);
            if(fu!=fv) f[fv]=fu;
        }
    }
    for(ll i=1,a,b;i<=m;++i){
        cin>>a>>b>>c;
        ll fu=findSet(a),fv=findSet(b);
        if(fu==fv&&s[fu]!=c) cout<<"0";
        else cout<<"1";
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}