#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=10010;
int n,m,q;
vector<int>fac(2*N,1),inv(2*N),p(2*N,1);
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
    for(int i=1;i<N;++i){
        fac[i]=fac[i-1]*i%q;
        p[i]=p[i-1]*2%q;
    }
    inv[N-1]=qpow(fac[N-1],q-2);
    for(int i=N-2;i>=0;--i) inv[i]=(inv[i+1])*(i+1)%q;
    int ans=0;
    function<int(int,int)> C=[&](int n,int r){
        return (fac[n]*inv[r]%q*inv[n-r]%q)%q;
    };
    for(int i=1;i<=n;++i)
        ans=(ans+C(n,i)*qpow(p[n-i],m-1)%q*(qpow(p[i]-1,m-1)))%q;
    cout<<ans<<"\n";
    return 0;
}