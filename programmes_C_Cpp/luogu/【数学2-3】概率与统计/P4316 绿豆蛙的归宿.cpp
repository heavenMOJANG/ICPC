#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{int to,nxt,w;};
void solve(){
    int n,m;cin>>n>>m;
    int idx=0;
    vector<int>head(n+1,-1),ind(n+1,0),oud(n+1,0);
    vector<Node>e(n<<1|1);
    auto addEdge=[&](int u,int v,int w){e[idx]={v,head[u],w},head[u]=idx++;};
    for(int i=0,u,v,w;i<m;++i) cin>>u>>v>>w,addEdge(u,v,w),ind[v]++,oud[u]++;
    vector<double>f(n+1,0.0),g(n+1,0.0);
    g[1]=1.0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];~i;i=e[i].nxt){
			int v=e[i].to;                           
			f[v]+=(f[u]+e[i].w*g[u])/oud[u]; 
			g[v]+=g[u]/oud[u];
		    ind[v]--;
			if(!ind[v]) q.push(v); 
		}
	}
    cout<<fixed<<setprecision(2)<<f[n]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
