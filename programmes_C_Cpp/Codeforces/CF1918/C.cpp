#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,b,r;cin>>a>>b>>r;
    int flag=1,cur=0;
    for(int i=60;i>=0;--i){
        int t1=a>>i&1,t2=b>>i&1;
        if(t1==t2) continue;
        if(flag){
            cur=(1ll<<i)*(t1-t2);
            flag=0;
        }
        else
            if(r>=(1ll<<i)&&(t1-t2)*cur>0) {
                r-=(1ll<<i);
                cur-=(t1-t2)*(1ll<<i);
            }
            else cur+=(t1-t2)*(1ll<<i);  
    }
    cout<<abs(cur)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
