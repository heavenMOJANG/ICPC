#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110][110];
char g[110][110];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j){
            cin>>g[i][j];
            if(g[i][j]=='*'){
                a[i-1][j-1]++; a[i-1][j]++; a[i-1][j+1]++;
                a[i][j-1]++;                a[i][j+1]++;
                a[i+1][j-1]++; a[i+1][j]++; a[i+1][j+1]++;
            }
        }
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=m;++j) if(g[i][j]=='*')cout<<"*";else cout<<a[i][j];
        cout<<"\n";
    }
    return 0;
}