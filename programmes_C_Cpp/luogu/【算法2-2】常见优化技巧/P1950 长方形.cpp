#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,top,l[1010],r[1010],h[1010],s[1010],res;
char g[1010][1001];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>g[i][j];
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=m;++j) h[j]=g[i][j]=='*'?0:h[j]+1;
        for(ll j=1;j<=m;++j){
            while(top&&h[j]<h[s[top]]) r[s[top--]]=j;
            s[++top]=j;
        }
        while(top) r[s[top--]]=m+1;
        for (ll j=m;j>=1;--j){
            while (top&& h[j] <= h[s[top]]) l[s[top--]]=j;
            s[++top] = j;
        }
        while(top) l[s[top--]]=0;
        for(ll j=1;j<=m;++j) res+=(j-l[j])*(r[j]-j)*h[j];
    }
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
