#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll x,y,z;
    cin>>x>>y>>z;
    if(z==0){
        if(x==0||y==0) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    ll gcd=__gcd(x,y);
    if(z%gcd==0) cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}