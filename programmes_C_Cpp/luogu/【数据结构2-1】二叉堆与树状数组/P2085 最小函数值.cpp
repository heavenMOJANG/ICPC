#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
priority_queue<ll>q;
ll n,m,ans[10010];
ll f(ll a,ll b,ll c,ll x){return a*x*x+b*x+c;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll a,b,c;cin>>a>>b>>c;
    for(ll i=1;i<=m;++i) q.push(f(a,b,c,i));
    for(ll i=2;i<=n;i++){
        cin>>a>>b>>c;
        for(ll j=1;j<=m;++j){
            if(f(a,b,c,j)<q.top()){
                q.pop();
                q.push(f(a,b,c,j));
            }
            else break;
        }
 
    }
    for(ll i=1;i<=m;++i) ans[i]=q.top(),q.pop();
    for(ll i=m;i>=1;--i) cout<<ans[i]<<" ";
    return 0;
}