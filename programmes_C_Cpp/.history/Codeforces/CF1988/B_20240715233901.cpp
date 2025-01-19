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
    vector<int>pre;
    map<int,int>mp;
    if(s[0]=='1') mp[1]++;
    else mp[0]++;
    for(int i=1;i<s.size();++i){
        if(s[i]=='1') mp[1]++;
        else{
            if(s[i-1]!=0) mp[0]++;
        }
    }
    cout<<(mp[1]>mp[0]?"Yes\n":"No\n");
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}