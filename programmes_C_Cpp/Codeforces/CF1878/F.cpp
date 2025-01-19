#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,q;cin>>n>>q;
    map<ll,ll>mp;
    ll mul=1;
    for(ll i=2;i*i<=n;++i)
        if(n%i==0){
            ll num=0;
            while(n%i==0) n/=i,num++;
            mp[i]=num;
            mul*=(num+1);
        }
    if(n>1) mp[n]=1,mul<<=1;
    map<ll,ll> mmp=mp;
    ll mmul=mul;
    while(q--){
        ll op;
        cin>>op;
        if(op==1){
            ll x;cin>>x;
            for(ll i=2;i*i<=x;++i)
                if(x%i==0){
                    ll num=0;
                    while(x%i==0) x/=i,num++;
                    mul/=mp[i]+1;
                    mp[i]+=num;
                    mul*=mp[i]+1;
                }
            if(x>1){
                mul/=mp[x]+1;
                mp[x]+=1;
                mul*=mp[x]+1;
            }
            ll t=mul;
            for(auto [x,y]:mp) while(y>0&&t%x==0) t/=x,y--;
            cout<<(t==1? "YES\n":"NO\n");
        }
        else{
            mp=mmp;
            mul=mmul;
        }
    }
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
