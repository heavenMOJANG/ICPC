#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=500010;
struct Node{}t[N<<2];
ll n,m,a[N];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    while(m--){
        ll op,l,r;cin>>op>>l>>r;
        switch(op){
            case 1:break;
            case 2:break;
            case 3:break;
            case 4:break;
            case 5:break;
        }
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
