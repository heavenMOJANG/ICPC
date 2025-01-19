#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5010;
int n,m,q;
vector<int>fac(2*N,1),inv(2*N);
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>q;
    function<int(int,int)> qpow=[&](int a,int n){
        int res=1;
        while(n){
            if(n&1) res=res*a%q;
            a=a*a%q;
            n>>=1;
        }
        return res;
    };
    for(int i=1;i<=10000;++i){
        fac[i]=fac[i-1]*i%q;
        inv[i]=qpow(fac[i],q-2);
    }
    int ans=qpow(2,m);
    function<int(int,int)> C=[&](int n,int r){
        return (fac[n]*inv[r]%q*inv[n-r]%q)%q;
    };
    for(int i=0;i<m;++i){
        ans=(ans+C(m-1,i)*qpow(2,m-1-i)%q)%q;
        cout<<C(m-1,i)<<"\n";
    }
    ans=(ans+qpow(2,m-1))%q;
    cout<<ans<<"\n";
    cout<<C(2,0)<<"\n";
    return 0;
}