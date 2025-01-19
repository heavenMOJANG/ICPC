#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[100010],d[100010],p,m;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i)
        cin>>a[i],d[i]=a[i]-a[i-1];
    for(ll i=2;i<=n;++i)
        if(d[i]>0) p+=d[i];
        else m+=-d[i];
    cout<<max(p,m)<<"\n"<<abs(p-m)+1;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}