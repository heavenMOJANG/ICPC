#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[100010],res;
void solve(){
    cin>>n;
    res=0;
    for(ll i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    if(a[n]!=1) cout<<"499122177\n";
    else if(n&1) cout<<"1\n";
    else cout<<"0\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}