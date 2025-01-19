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
    auto check=[&](ll x){return __int128_t(x)*(x - 1)/2;};

        ll l=0,r=2648956421;
        while(l<r){
            ll mid=l+r>>1;
            if (check(mid)>=n) r=mid;
            else l=mid+1;
        }
        if(r*(r-1)/2==n)
            cout<<r<<"\n";
        else
            cout<<r-1+n-(r-1)*(r-2)/2<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
