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
    int cnt=0;
    for(int i=0;i<n;++i)
        if(s[i]=='p'){
            int flag=0;
            if(i>2&&s[i-2]=='m'&&s[i-1]=='a') flag=1;
            if(i+2<n&&s[i+1]=='i'&&s[i+2]=='e') flag=1;
            if(flag) cnt++;
        }
    cout<<cnt<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
