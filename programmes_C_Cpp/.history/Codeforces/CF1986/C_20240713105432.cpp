#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<int>a(m);
    map<int,int>mp;
    for(int i=0;i<m;++i) mp[a[i]]++;
    vector<char>c(m);
    string t;cin>>t;
    for(int i=0;i<m;++i) c[i]=t[i];
    sort(c.begin(),c.end());
    int id=0;
    for(auto it:mp){
        int x=it.first;
        s[--x]=c[id++];
    }
    for(int i=0;i<n;++i) cout<<s[i]<<"\n"[i==n-1];
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}