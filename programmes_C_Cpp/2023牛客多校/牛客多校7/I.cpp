#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll n;
string s;
vector<string>v[410];
ll summary(ll len){
    ll fac[len+1],res=1;
    fill(fac,fac+len,1);
    for(ll j=0;j<len;++j){
        ll num[2]={0,0},f=0;
        for(string s:v[len]){
            if(s[j]=='?') f=1;
            else num[s[j]-48]++;
        }
        if(f||(num[0]&&num[1])) fac[j]=2;
    }
    for(ll i=0;i<len;++i) res=res*fac[i]%mod;
    return res;
}
void solve(){
    cin>>n;
    ll sum=0;
    for(ll i=1;i<=400;++i) v[i].clear();
    for(ll i=1;i<=n;++i){
        cin>>s;
        v[s.size()].push_back(s);
    }
    for(ll i=1;i<=400;++i) if(v[i].size()) sum=(sum+summary(i))%mod;
    cout<<sum;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}