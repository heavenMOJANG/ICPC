#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,d,s[100010];
void solve(){
    cin>>n>>m>>d;
    for(ll i=1;i<=m;++i) cin>>s[i];
    s[0]=1;s[m+1]=n+1;
    ll sum=1;
    for(ll i=1;i<=m+1;++i){
        sum+=(s[i]-s[i-1]-1)/d;
        if(s[i]!=1&&s[i]!=n+1) sum+=1;
    }
    ll minn=LLONG_MAX,res=0;
    for(ll i=1;i<=m;++i){
        ll tmp=sum;
        tmp-=(s[i]-s[i-1]-1)/d+(s[i+1]-s[i]-1)/d;
        if(s[i]!=1) tmp-=1;
        tmp+=(s[i+1]-s[i-1]-1)/d;
        if(minn>tmp) minn=tmp,res=1;
        else if(minn>=tmp) res++;
    }
    cout<<minn<<" "<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
