#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[270000];
void solve(){
    ll res=0;
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i],res^=a[i];
    if(n==1){cout<<a[1]<<"\n";return;}
    if(res!=0){cout<<"-1\n";return;}
    
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
