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
    vector<ll>a(n);
    for(ll i=0;i<n;++i) cin>>a[i];
    vector<ll>ans{a[0]};
    for(ll i=1;i<n;++i){
        if(a[i]<ans.back()) ans.push_back(a[i]); 
        ans.push_back(a[i]);
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans) cout<<x<<" ";
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
