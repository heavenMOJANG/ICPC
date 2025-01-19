#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    if(k==1){cout <<"1\n";return;}
    if(k>3){cout<<"0\n";return;}
    int res=0;
    if(m<n){
        if(k==2)cout<<m<<"\n";
        else cout<<"0\n";
    }
    else{
        res+=n-1+m/n;
        if(k==2) cout<<res<<"\n";
        else cout <<m-res<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
