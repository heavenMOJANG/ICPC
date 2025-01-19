#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int p=n;
    for(int i=0;i<n-1;++i) if(s[i]=='*'&&s[i+1]=='*'){p=i;break;}
    int sum=0;
    for(int i=0;i<p;++i) if(s[i]=='@') sum++;
    cout<<sum<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
