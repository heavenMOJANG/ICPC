#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int check(int x){
    string s=to_string(x);
    for(int i=0;i<s.size();++i)
        if(s[i]!='0'&&s[i]!='1') return 0;
    return 1;
}
void solve(){
    int n;cin>>n;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    vector<int>p;
    for(int i=2;i<=1000000;++i) if(check(i)) p.push_back(i);
    while(_--) solve();
    return 0;
}
