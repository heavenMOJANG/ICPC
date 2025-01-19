#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,a[1000010],l,r,minn=LLONG_MAX,qL,qR;
map<ll,ll>mp;
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    l=1,r=1;
    mp[a[r]]++;
    while(r<=n){
        if(mp.size()==m){
            if(r-l+1<minn){
                minn=r-l+1;
                qL=l,qR=r;
            }
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }
        else{
            r++;
            mp[a[r]]++;
        }
    }
    cout<<qL<<" "<<qR;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}