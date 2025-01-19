#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,b,l;cin>>a>>b>>l;
    set<int>s;
    int ll=l,x=0,y=0;
    while(ll!=1&&ll%a==0) x++,ll/=a;
    ll=l;
    while(ll!=1&&ll%b==0) y++,ll/=b;
    for(int i=0;i<=x;++i)
        for(int j=0;j<=y;++j){
            int tmp=pow(a,i)*pow(b,j);
            if(tmp>l) continue;
            if(l%tmp==0) s.insert(l/tmp);
        }
    cout<<s.size()<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
