#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=10007;
ll n,m,a[100010],res,sum;
vector<ll>odd[100010],even[100010];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1,x;i<=n;++i){
        cin>>x;
        if(i&1) odd[x].push_back(i);
        else even[x].push_back(i);
    }
    for(ll i=1;i<=m;++i){
        sum=0;
        ll siz=odd[i].size();
        for(auto x:odd[i]) sum+=a[x]%mod;
        for(auto x:odd[i]){
            res+=((siz-2)%mod*x%mod*a[x]%mod+x%mod*sum%mod)%mod;
            res%=mod;
        }
        sum=0;
        siz=even[i].size();
        for(auto x:even[i]) sum+=a[x]%mod;
        for(auto x:even[i]){
            res+=((siz-2)%mod*x%mod*a[x]%mod+x%mod*sum%mod)%mod;
            res%=mod;
        }
    }
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}