#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    int fac=0;
    for(int i=2;i<=sqrt(n);++i) if(n%i==0){fac=i;break;}
    while(fac&&n%fac==0) n/=fac;
    if(fac!=0&&n!=1) cout<<"Yes\n";
    else cout<<"No\n";
    return;
}
signed main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
