#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,T,maxn,t;
void solve(){
    cin>>n>>T;
    while(n--) cin>>t,maxn=max(maxn,t);
    cout<<max(2ll,ll(ceil(maxn*1.0/(T*1.0))));
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
