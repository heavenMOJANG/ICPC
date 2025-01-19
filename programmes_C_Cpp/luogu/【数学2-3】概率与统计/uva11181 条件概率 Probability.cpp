#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
int idx;
void solve(){
    int n,r;
    while(cin>>n>>r,n||r){
        cout<<"Case "<<++idx<<":\n";
        vector<double>p(n),sum(n,0.0);
        vector<int>vis(n,0);
        double tot=0;
        for(int i=0;i<n;++i) cin>>p[i];
        function<void(int,int)> dfs=[&](int x,int rest){
            if(!rest){
		        double tmp=1.0;
		        for(int i=0;i<n;++i) tmp*=(vis[i]?p[i]:1.0-p[i]);
		        tot+=tmp;
		        for(int i=0;i<n;++i) if(vis[i]) sum[i]+=tmp/p[i];
		        return;
	        }
	        for(int i=x;i<n;++i){
		        if(n-i<rest) return;
		        vis[i]=1;
		        dfs(i+1,rest-1);
		        vis[i]=0;
	        }
        };
        dfs(0,r);
        for(int i=0;i<n;++i) cout<<fixed<<setprecision(6)<<(sum[i]*p[i]/tot)<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
