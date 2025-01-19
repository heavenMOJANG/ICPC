#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll T,n,a[100010],b[100010];
ll gcd(ll a,ll b){
    if(!a) return 0;
    if(!b) return 1;
    if(a>=b){
        ll r=a%b,k=a/b;
        if(k&1) return gcd(b,r)+k+k/2;
        else return gcd(r,b)+k+k/2;
    }
    return 1+gcd(b,abs(a-b));
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(ll i=1;i<=n;++i) cin>>a[i];
        for(ll i=1;i<=n;++i) cin>>b[i];
        set<ll>s;
        for(ll i=1;i<=n;++i){
            if(!a[i]&&!b[i]) continue;
            s.insert(gcd(a[i],b[i])%3);
        }
        cout<<(s.size()<=1?"YES\n":"NO\n");
    }
    return 0;
}