#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s[2];cin>>s[0]>>s[1];
    string ans=s[0]+s[1][n-1];
    int p=n-1;
    for(int i=1;i<n;++i)
        if(s[0][i]=='1'&&s[1][i-1]=='0'){
            ans=s[0].substr(0,i);
            ans+=s[1].substr(i-1);
            p=i-1;
            break;
        }
    int cnt=1;
    for(int i=p;i;--i){
        if(s[0][i]!=s[1][i-1]) break;
        cnt++;
    }
    cout<<ans<<"\n"<<cnt<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
