#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,k,x;
void solve(){
    cin>>n>>k>>x;
    if(n<k||x<k-1){cout<<"-1\n";return;}
    ll res=(k-1)*k/2;
    if(x==k) res+=(x-1)*(n-k);
    else res+=x*(n-k);
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
