#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll m,k,a1,ak;
void solve(){
    cin>>m>>k>>a1>>ak;
    ll dk=m/k,d1=m%k;
    if(a1>=d1){
        a1-=d1;
        ak+=a1/k;
        cout<<max(0ll,dk-ak)<<"\n";
    }
    else cout<<max(0ll,dk-ak)+d1-a1<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
