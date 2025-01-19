#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,x=0,y;
    cin>>n;
    vector<ll>a(n+1);
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<=n;++i) if(a[i]==x) x++;
    while(1){
        cout<<x<<endl;
        cin>>y;
        if(y==-1) break;
        x=y;
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
