#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5010;
int n,m,q;
vector<int>f(2*N,1),inv(2*N);
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
    for(int i=2;i<=5000;++i){
        f[i]=f[i-1]*i%q;
        inv[i]=qpow(f[i],q-2);
    }
    int ans=n;
    function<int(int,int)> C=[&](int n,int r){
        return (f[n]*inv[r]%q*inv[n-r]%q)%q;
    };
    for(int i=0;i<m;++i){
        ans=(ans+C(n,i))
    }
    cout<<ans-1<<"\n";
    return 0;
}