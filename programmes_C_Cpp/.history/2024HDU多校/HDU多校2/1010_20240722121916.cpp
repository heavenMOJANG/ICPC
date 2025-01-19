#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    map<char,int>mp;
    for(auto ch:s) mp[ch]++;
    queue<char>q;
    for(auto ch:s) q.push(ch);
    while(q.size()!=2){
        char u=q.front();q.pop();
        char v=q.front();q.pop();
        q.push(u);
    }
    int u=q.front();q.pop();
    int v=q.front();q.pop();
    if(u==v){cout<<u<<"\n";return;}
    if(mp[u]>mp[v]) cout<<u<<"\n";
    else if(mp[u]<mp[v]) cout<<v<<"\n";
    else cout<<"N\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}