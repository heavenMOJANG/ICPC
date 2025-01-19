#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,h[500000][101],top[500000],idx;
string s;
map<string,ll>mp;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,l;i<=n;++i){
        cin>>l;
        for(ll j=1;j<=l;++j){
            cin>>s;
            if(mp[s]==0) mp[s]=++idx;
            ll tmp=mp[s];
            if(h[tmp][top[tmp]]==i) continue;
            h[tmp][++top[tmp]]=i;
        }
    }
    cin>>m;
    for(ll i=1;i<=m;++i){
        cin>>s;
        ll tmp=mp[s];
        for(ll i=1;i<=top[tmp];++i) cout<<h[tmp][i]<<" ";
        cout<<"\n";
    }
    return 0;
}