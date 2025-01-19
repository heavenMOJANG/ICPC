#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
constexpr ll inf=0x7fffffff;
ld a,b;
ll c;
void solve(){
    cin>>a>>b>>c;
    if(a==b){cout<<"0\n";return;}
    ld mid=(a+b)/2;
    ll ans=ceil((max(a,b)-mid)/c);
    cout<<ans<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
