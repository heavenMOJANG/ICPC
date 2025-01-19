#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,g[40][40];
void dfs(ll x,ll y) {
	if(x<1||y<1||x>n||y>n||g[x][y]!=0) return;
	g[x][y]=-1;
    dfs(x-1,y);
    dfs(x,y+1);
	dfs(x+1,y);
	dfs(x,y-1);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j) cin>>g[i][j];
	for(ll i=1;i<=n;++i){
		if(g[i][1]!=1) dfs(i,1);
		if(g[i][n]!=1) dfs(i,n);
	}
	for(ll i=1;i<=n;++i){
		if(g[1][i]!=1) dfs(1,i);
		if(g[n][i]!=1) dfs(n,i);
	}
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j)
            switch(g[i][j]){
                case -1:cout<<"0 ";break;
                case 1:cout<<"1 ";break;
                default:cout<<"2 ";
            }
		cout<<"\n";
	}
    return 0;
}