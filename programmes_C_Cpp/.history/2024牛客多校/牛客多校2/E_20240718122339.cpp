#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
map<int,int>mp;
void solve(){
    int x;cin>>x;
    if(mp[x]==1){cout<<"-1\n";return;}
    if(x&1) cout<<x-1<<"\n";
    else{
        for(int i=0;i<=63;++i){
            int t=1ll<<i;
            if(t&x==1){cout<<x-t<<"\n";break;}
        }
    }
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<=63;++i) mp[1ll<<i]=1; 
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}