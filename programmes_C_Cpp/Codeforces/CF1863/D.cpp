#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
char g[510][510],a[510][510];
ll n,m;
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>a[i][j],g[i][j]='.';
    ll mark=1;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j){
            if(g[i][j]!='.'||(a[i][j]!='U'&&a[i][j]!='L')) continue;
            ll flag=1;
            if(a[i][j]=='L'){
                g[i][j]='W';
                g[i][j+1]='B';
                for(ll k=i+1;k<=n;++k)
                    if(a[k][j]=='L'){
                        g[k][j]='B';
                        g[k][j+1]='W';
                        flag=0;
                        break;
                    }
            }
            if(a[i][j]=='U'){
                g[i][j]='W';
                g[i+1][j]='B';
                for(ll k=j+1;k<=m;++k)
                    if(a[i][k]=='U'){
                        g[i][k]='B';
                        g[i+1][k]='W';
                        flag=0;
                        break;
                    }
            }
            if(flag) mark=0;
        }
        if(mark)
            for(ll i=1;i<=n;++i){
                for(ll j=1;j<=m;++j) cout<<g[i][j];
                cout<<"\n";
            }
        else cout<<"-1\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
