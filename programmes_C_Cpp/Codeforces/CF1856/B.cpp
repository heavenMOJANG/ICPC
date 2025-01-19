#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[100010];
void solve(){
    cin>>n;
    ll sum=0,cnt=0;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==1) cnt+=1;
        sum+=a[i]-1;
    }
    if(n==1){cout<<"NO\n";return;}
    if(sum>=cnt) cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}