#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m;
string s;
void solve(){
    getline(cin,s);
    cin>>n>>m;cin.get();
    vector<ll>v;v.push_back(0);
    ll tmp=0,cnt=1;
    for(char ch:s){
        if('0'<=ch&&ch<='9') tmp=tmp*10+ch-'0';
        if(ch==','||ch==']') v.push_back(tmp),tmp=0;
    }
    cout<<"[";
    cout<<"["<<v[cnt++];
    for(ll j=2;j<=m;++j) cout<<", "<<v[cnt++];
    cout<<"]";
    for(ll i=2;i<=n;++i){
        cout<<", ["<<v[cnt++];
        for(ll j=2;j<=m;++j) cout<<", "<<v[cnt++];
        cout<<"]";
    }
    cout<<"]\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;cin.get();
    while(_--) solve();
    return 0;
}
