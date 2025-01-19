#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,c;
map<string,ll>mp;
string s;
vector<string>v;
ll cmp(string x,string y){return x<y;}
void solve(){
    ll n;cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>c;
        while(c--) cin>>s,mp[s]++;
    }
    for(auto it=mp.begin();it!=mp.end();++it) if(it->second==n) v.push_back(it->first);
    sort(v.begin(),v.end(),cmp);
    cout<<v.size()<<"\n";
    for(auto x:v) cout<<x<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}