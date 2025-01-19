#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[200010];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    if(n==1){cout<<"0\n";return;}
    vector<array<ll,2>>s(n+1);
    for(ll i=1;i<n;++i){
        s[i]=s[i-1];
        if(a[i]>=a[i+1]) s[i][0]+=1;
        if(a[i]<=a[i+1]) s[i][1]+=1;
    }
    ll res=min(s[n-1][0],s[n-2][1]+1),cnt=0;
    for(ll i=n-1;i>=2;--i){
        cnt+=(a[i]>=a[i+1]);
        res=min(res,cnt+s[i-2][1]+1);
    }
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
