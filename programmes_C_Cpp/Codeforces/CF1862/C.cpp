#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n;
void solve(){
    cin>>n;
    vector<ll>a(n+1),b(n+1);
        for(ll i=1;i<=n;++i) cin>>a[i];
        for(ll i=1,j=n;i<=n;++i){
            while(j>=1&&a[j]<i) j--;
            b[i]=j;
        }
        cout<<(a==b?"YES\n":"NO\n");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
