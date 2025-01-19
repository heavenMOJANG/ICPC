#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,f[2010],res;
ll find_set(ll x){return f[x]==x?x:find_set(f[x]);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=(n<<1);++i) f[i]=i;
    for(ll i=1,p,q;i<=m;++i){
        char opt;
        cin>>opt>>p>>q;
        switch(opt){
            case 'E':f[find_set(p+n)]=find_set(q),f[find_set(q+n)]=find_set(p);break;
            case 'F':f[find_set(p)]=find_set(q);break;
        }
    }
    for(ll i=1;i<=n;++i) res+=(f[i]==i);
    cout<<res;
    return 0;
}