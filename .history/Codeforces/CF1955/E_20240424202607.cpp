#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;s=" "+s;
    auto check=[&](int mid){
        vector<int>a(n+1);
        int tmp=0;
        for(int i=1,j=0;i<=n;++i){
            tmp+=a[i];
            if((s[i]-'0'+(tmp&1))%2==1) continue;
            tmp++;
            if(i+mid-1>n) return 0;
            if(i+mid<=n) a[i+mid]--;
        }
        return 1;
    };
    int ans=1;
    for(int i=1;i<=n;++i) if(check(i)) ans=i;
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}