#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,vis[100010];
void solve(){
    cin>>n;
    fill(vis+1,vis+1+n,0);
    for(ll i=1;i<=n;++i){
        if(vis[i]) continue;
        ll tmp=i;
        while(tmp<=n){
            cout<<tmp<<" ";
            vis[tmp]=1;
            tmp<<=1;
        }
    }
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
