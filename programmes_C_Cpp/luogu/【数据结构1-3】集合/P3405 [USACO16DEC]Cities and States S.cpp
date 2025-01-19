#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
map<ll,ll>mp[200010];
ll n,res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i){
        string a,b;
        cin>>a>>b;
        ll u=a[0]*26+a[1],v=b[0]*26+b[1];
        res+=mp[v][u];
        if(u==v) res-=mp[u][v];
        mp[u][v]++;
    }
    cout<<res;
    return 0;
}