#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
const string s="vika";
ll n,m;
void solve(){
    cin>>n>>m;
    vector<string>g(m);
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            char c;cin>>c;
            g[j]+=c;
        }
    }
    ll res=0;
    for(ll i=0;i<m&&res!=4;++i) if(g[i].find(s[res])!=string::npos) res++;
    cout<<(res==4?"Yes\n":"No\n");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
