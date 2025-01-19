#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll dx[]={0,1,0,-1,1,-1,1,-1};
ll dy[]={1,0,-1,0,-1,1,1,-1};
char g[110][110];
int n,a[110][110];
string s="yizhong";
struct Node{ll x,y;}res[7];
void dfs(ll x,ll y,ll d,ll num){
	if(num==7)
		for(ll i=0;i<7;++i)
			a[res[i].x][res[i].y]=1;
	else
		if(g[x][y]==s[num]){
			res[num].x=x;
			res[num].y=y;
			dfs(x+dx[d],y+dy[d],d,num+1);
		}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(ll i=0;i<n;++i)
		for(ll j=0;j<n;++j) cin>>g[i][j];
	for(ll i=0;i<n;++i)
		for(ll j=0;j<n;++j) if(g[i][j]=='y') for(ll k=0;k<8;++k) dfs(i,j,k,0);
    for(ll i=0;i<n;++i){
		for(ll j=0;j<n;++j)
			if(a[i][j]==1) cout<<g[i][j];
			else cout <<'*';
		cout<<"\n";
	}
    return 0;
}