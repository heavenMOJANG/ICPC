#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>ans(1010,0);
    for(int i=1;i<=1000;++i)
        for(int j=1;j<=i;++j) ans[i]+=(i%j==0?j:0ll);
    int n,idx=0;
    while(cin>>n,n){
        int flag=0;
        for(int i=1000;i;--i) if(ans[i]==n){cout<<"Case "<<++idx<<": "<<i<<"\n";flag=1;break;}
        if(!flag) cout<<"Case "<<++idx<<": -1\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
