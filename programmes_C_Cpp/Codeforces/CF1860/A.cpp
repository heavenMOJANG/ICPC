#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    string s,s1="",s2="";
    cin>>s;
    ll n=s.size();
    for(ll i=1;i<=n;++i) s1+="()";
    for(ll i=1;i<=n;++i) s2+="(";
    for(ll i=1;i<=n;++i) s2+=")";
    s1+="\n";s2+="\n";
    if(s1.find(s)==string::npos){cout<<"YES\n"<<s1;return;}
    if(s2.find(s)==string::npos){cout<<"YES\n"<<s2;return;}
    cout<<"NO\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
