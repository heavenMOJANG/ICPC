#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll a,b,p,f[100010],pr[100010],res;
ll find_set(ll x){return f[x]==x?x:find_set(f[x]);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>p;
    for(ll i=a;i<=b;++i) f[i]=i;
    res=b-a+1;
    for(ll i=2;i<=b;++i){
        if(!pr[i]){
            if(i>=p)
                for(ll j=2;j*i<=b;++j){
                    pr[j*i]=1;
                    if(j*i-i>=a&&find_set(j*i)!=find_set(j*i-i))
                        f[find_set(j*i)]=find_set(j*i-i),res--;
                }
            else for(ll j=2;j*i<=b;++j) pr[j*i]=1;
        }
    }
    cout<<res;
    return 0;
}