#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;
    while(cin>>n>>m){
        if(!(n+m)) return;
        if(m<n) swap(n,m);
        cout<<n*m*(n+m-2)+2*n*(n-1)*(3*m-n-1)/3<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
