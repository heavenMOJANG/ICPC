#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll x,a,b,cnt;
void solve(){
    cin>>x>>a>>b;
    cnt=0;
    while(x){
        ll t1=x-1,t2=(x+a)/2,t3=sqrt(x+b);
        if(t1<t2&&t1<t3){cout<<x+cnt<<"\n";return;}
        x=min({t1,t2,t3});
        cnt++;
    }
    cout<<cnt<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}