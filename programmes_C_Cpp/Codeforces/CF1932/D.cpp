#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    map<char,vector<int>>cd;
	int n;cin>>n;
    char trump;cin>>trump;
    string s;
    for(int i=1;i<=2*n;++i){
        cin>>s;
        cd[s[1]].emplace_back(s[0]-'0');
    }
    int need=0;
    for(auto & [k,v]:cd){
        sort(v.begin(),v.end());
        if(k==trump) continue;
        if(((int)v.size())&1) ++need;
    }
    if(need>(int)cd[trump].size()){cout<<"IMPOSSIBLE"<<'\n';return;}
    int j=0;
    for(auto&[k,v]:cd){  
        if(k==trump) continue;
        int sz=v.size();
        for(int i=0;i+1<sz;i+=2) cout<<v[i]<<k<<" "<<v[i+1]<<k<<'\n';
        if(sz&1) cout<<v[sz-1]<<k<<" "<<cd[trump][j++]<<trump<<'\n';
    }
    int sz=cd[trump].size();
    for(;j<sz;j+=2) cout<<cd[trump][j]<<trump<<" "<<cd[trump][j+1]<<trump<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
