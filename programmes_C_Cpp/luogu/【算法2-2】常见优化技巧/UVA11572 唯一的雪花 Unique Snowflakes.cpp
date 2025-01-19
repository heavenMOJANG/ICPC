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
    vector<ll>a(n+1);
    map<ll,ll>mp;
    for(ll i=1;i<=n;++i) cin>>a[i];
    ll l=1,r=1,maxn=0;
    mp[a[r]]++;
    while(r<=n){
        if(mp[a[r]]==1) maxn=max(maxn,(ll)mp.size()),mp[a[++r]]++;
        else{
            while(mp[a[r]]!=1){
                mp[a[l]]--;
                if(mp[a[l]]==0) mp.erase(a[l]);
                l++;
            }
            maxn=max(maxn,(ll)mp.size());
        }    
    }
    cout<<maxn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
