#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
string g[1010][1010];
ll n,m,h[1010][1010],s[1010],top,l[1010],r[1010];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>g[i][j];
    for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
			for(ll k=i;k>0&&g[k][j][0]=='F';--k) h[i][j]++;
    ll res=0;
    for(ll i=1;i<=n;++i){
		top=0;
		for(ll j=1;j<=m;++j){
			while(top&&h[i][s[top]]>=h[i][j]) top--;
			l[j]=s[top];
			s[++top]=j;
		}
		top=0;
		for(ll j=m;j>0;--j){
			while(top&&h[i][s[top]]>=h[i][j]) top--;
			if(!top) r[j]=m+1;
			else r[j]=s[top];
			s[++top]=j;
		}
		for(ll j=1;j<=m;++j) res=max(res,(r[j]-1-l[j])*h[i][j]);
	}
    cout<<3*res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
