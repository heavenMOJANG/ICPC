#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
char s[100010];
void solve(){
    int n;cin>>n;
    cin>>s;
    for(int i=n;i;--i) s[i]=s[i-1];
    int s0=0,s1=0;
    for(int i=1;i<=n;++i)
        if(s[i]=='0') s0++;
        else s1++;
    if(s1!=s0){cout<<"-1\n";return;}
    auto mdf=[&](int x){
        for(int i=n;i>x;i--) s[i+2]=s[i];
        s[x+1]='0',s[x+2]='1';
        n+=2;
    };
    vector<int>ans;
    for(int l=1,r=n;l<=r;l++,r--){
        if(s[l]!=s[r]) continue;
        if(s[l]=='0') ans.push_back(r),mdf(r),r+=2;
        if(s[l]=='1') ans.push_back(l-1),mdf(l-1),r+=2;
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans) cout<<x<<" ";
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
