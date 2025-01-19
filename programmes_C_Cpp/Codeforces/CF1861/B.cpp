#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
string s,t;
void solve(){
    cin>>s>>t;
    ll n=s.size();
    vector<ll>dp(n+1);
    dp[0]=1;
    for(ll i=0;i<n;++i)
        for(ll j=0;j<=i;++j)
            if(s[i]==t[i]&&s[j]==t[j]&&s[i]==s[j]&&dp[j]) dp[i+1]=1;
    cout<<(dp[n]?"YES\n":"NO\n");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
