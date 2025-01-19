#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m;
string s;
map<string,ll>mp;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>s,mp[s]=1;
    cin>>m;
    for(ll i=1;i<=m;++i){
        cin>>s;
        if(mp.find(s)==mp.end()){cout<<"WRONG\n";continue;}
        if(mp[s]==2){cout<<"REPEAT\n";continue;}
        cout<<"OK\n";mp[s]=2;
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
