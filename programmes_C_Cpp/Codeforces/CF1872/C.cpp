#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll l,r;
void solve(){
    cin>>l>>r;
    for(ll i=2;i*i<=r;++i){
        ll mul=(l+i-1)/i*i; //最小的a+b的值
        if(mul>r) continue;
        ll a=i,b=mul-i;
        if(b==0) b+=i;
        if(a+b>r) continue;
        cout<<a<<" "<<b<<"\n";
        return;
    }
    cout<<"-1\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
