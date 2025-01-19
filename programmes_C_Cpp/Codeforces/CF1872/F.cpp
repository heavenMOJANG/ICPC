#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n;cin>>n;
    vector<ll>a(n),c(n),d(n);
    for(ll i=0;i<n;++i) cin>>a[i],a[i]--,d[a[i]]++;
    for(ll i=0;i<n;++i) cin>>c[i];
    vector<ll>p0,p1,vis(n,-1),cyc(n);
    for(ll i=0;i<n;++i){
        if(vis[i]!=-1) continue;
        ll j;
        for(j=i;vis[j]==-1;j=a[j]) vis[j]=i;
        if(vis[j]!=i) continue;
        vector<ll>v;
        ll k=j;
        do{
            v.push_back(k);
            cyc[k]=1;
            k=a[k];
        }while(k!=j);
        ll mn=inf,ed=0,sz=v.size();
        for(ll i=0;i<v.size();++i) if(c[v[i]]<mn) mn=c[v[i]],ed=i;
        for(ll i=0;i<v.size();++i) p1.push_back(v[(i+ed+1)%sz]);
    }
    queue<ll>q; 
    for(ll i=0;i<n;++i) if(d[i]==0) q.push(i); 
    while(q.size()){
        ll u=q.front();q.pop();
        p0.push_back(u);
        d[a[u]]--;
        if(d[a[u]]==0) q.push(a[u]);
    }
    for(auto x:p0) cout<<x+1<<" ";
    for(auto x:p1) cout<<x+1<<" ";
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
