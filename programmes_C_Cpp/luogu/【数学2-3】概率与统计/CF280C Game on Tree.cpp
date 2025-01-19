#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Edge{int to,nxt;};
void solve(){
    int n;cin>>n;
    vector<int>head(n+1,-1);
    vector<Edge>e(n<<1|1);
    int idx=0;
    auto addEdge=[&](int u,int v){e[idx]={v,head[u]},head[u]=idx++;};
    for(int i=1,u,v;i<n;++i) cin>>u>>v,addEdge(u,v),addEdge(v,u);
    double res=0.0;
    function<void(int,int,int)> dfs=[&](int u,int fa,int depth){
	    res+=1.000/depth;
	    for(int i=head[u];~i;i=e[i].nxt){
		    int v=e[i].to;
		    if(v==fa) continue;
		    dfs(v,u,depth+1);
	    }
	    return;
    };
    dfs(1,-1,1);
    cout<<fixed<<setprecision(9)<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
