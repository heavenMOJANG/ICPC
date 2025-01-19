#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    if(n==1){cout<<k<<"\n";return;}
    vector<int>v;
    int len=floor(log2(k))+1,flag=0;
    for(int i=len;i>=0;--i){
        if(!(k&(1ll<<i))){
            int b=(1ll<<(i+1))-1;
            cout<<k-b<<" "<<b;
            flag=1;
            break;
        }
    }
    if(!flag){
        cout<<k;
        for(int i=1;i<n;++i) cout<<" 0";
    }
    else
        for(int i=2;i<n;++i) cout<<" 0";
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}