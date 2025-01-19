#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[200010];
void solve(){
    ll sum=0;
    cin>>n;
    for(ll i=0;i<n;++i) cin>>a[i],sum+=a[i];
    if(sum%n!=0){cout<<"No\n";return;}
    ll avg=sum/n,flag=1;
    vector<ll>n1(100),n2(100),n3(100),n4(100);
    auto cal=[&](ll x){
        ll cnt0=0,cnt1=0,t=abs(x);
        while(t){
            if(t&1) cnt1++;
            else{
                cnt0++;
                if(cnt1){flag=0;return;}
            }
            t>>=1;
        }
        if(x>0){
            if(cnt1==1) n4[cnt0]++;
            else n1[cnt0]++,n2[cnt0+cnt1]++; 
        }
        else{
            if(cnt1==1) n3[cnt0]++;
            else n2[cnt0]++,n1[cnt0+cnt1]++;
        }
    };
    for(ll i=0;i<n;++i){
        ll t=a[i]-avg;
        if(t) cal(t);
        if(!flag){cout<<"No\n";return;}
    }
    for(ll i=30;i>=0;--i){
        n1[i]+=n3[i],n2[i]+=n4[i];
        if(n1[i]!=n2[i]){
            if(!i){cout<<"No\n";return;}
            if(n1[i]<n2[i]){
                ll d=n2[i]-n1[i];
                if(d>n3[i-1]){cout<<"No\n";return;}
                n3[i-1]-=d,n2[i-1]+=d;
            }
            else if(n1[i]>n2[i]){
                ll d=n1[i]-n2[i];
                if(d>n4[i-1]){cout<<"No\n";return;}
                n4[i-1]-=d,n1[i-1]+=d;
            }
        }
    }
    cout<<"Yes\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
