#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n;cin>>n;
    vector<ll>s(n),e(n);
    cin>>s[0]>>e[0];
    ll flag=0;
    for(ll i=1;i<n;++i){
        cin>>s[i]>>e[i];
        if(s[i]>=s[0]&&e[i]>=e[0]) flag=1;
    }
    if(flag) cout<<"-1\n";
    else cout<<s[0]<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
