#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a,b,vis[210],s[210],d[210];
ll bfs(){
    queue<ll>q;
    q.push(a);
    while(!q.empty()){
        ll u=q.front();q.pop();
        if(u==b) return s[b];
        if(u-d[u]>=1&&!vis[u-d[u]]) s[u-d[u]]=s[u]+1,q.push(u-d[u]),vis[u-d[u]]=1;
        if(u+d[u]<=n&&!vis[u+d[u]]) s[u+d[u]]=s[u]+1,q.push(u+d[u]),vis[u+d[u]]=1;
    }
    return -1;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>a>>b;
    for(ll i=1;i<=n;++i) cin>>d[i];
    cout<<bfs();
    return 0;
}