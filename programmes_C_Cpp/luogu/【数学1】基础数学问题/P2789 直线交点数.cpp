#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,res,f[10010];
void dfs(ll p,ll m){
    if(!p){
        if(!f[m]) res++;
        f[m]=1;
    }
    else
        for(ll r=p;r>=1;--r) dfs(p-r,r*(p-r)+m);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    dfs(n,0);
    cout<<res;
    return 0;
}
