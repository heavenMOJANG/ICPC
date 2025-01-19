#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;string s,ans;
    cin>>n;cin>>s;
    int sum=0;
    for(auto&c:s) sum+=(c-'0');
    int carry=0;
    for(int i=n-1;i>=0;--i){
        int cur=(sum+carry)%10;
        ans.append(1,cur+'0');
        carry=(sum+carry)/10;
        sum-=(s[i]-'0');
    }
    if(carry) ans.append(1,carry+'0');
    while(!ans.empty()&&ans.back()=='0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
