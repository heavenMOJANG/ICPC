#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Edge{ll to,nxt;}edge[1000010];
ll n,head[1010],len[1010],vis[1010],idx,cnt,ans[1010],vl[1010],deg[30];
string s[1010];
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void writeln(){
    for(ll i=1;i<=cnt;++i) cout<<s[ans[i]]<<(i==cnt?"\n":".");
    exit(0);
}
void dfs(ll u){
    vl[u]=vis[u]=1;
    ans[++cnt]=u;
    for(ll i=head[u];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        if(!vis[v]) dfs(v);
    }
    if(cnt==n) writeln();
    vis[u]=0;
    cnt--;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>s[i];
    sort(s+1,s+1+n);
    for(ll i=1;i<=n;++i) len[i]=s[i].size();
    for(ll i=1;i<=n;++i)
        for(ll j=n;j>=1;--j) if(i!=j&&s[i][len[i]-1]==s[j][0]) add_edge(i,j);
    for(ll i=1;i<=n;++i){
        deg[s[i][0]-'a']++;
        deg[s[i][len[i]-1]-'a']--;
    }
    ll p1=0,p2=0,S;
    for(int i=0;i<26;++i)
        if(deg[i]==1) p1++,S=i;
        else if(deg[i]==-1) p2++;
    if(p1==1&&p2==1) for(ll i=1;i<=n;++i){if(s[i][0]-'a'==S) dfs(i);}
    else if(!p1&&!p2) for(ll i=1;i<=n;++i) dfs(i);
    cout<<"***";
    return 0;
}