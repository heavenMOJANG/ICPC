#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5010;
int n,m,q;
vector<int>f(N,1);
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>q;
    int base=1ll<<m,odd=base>>1;
    for(int i=2;i<=5000;++i) f[i]=f[i-1]*i%q;
    function<int(int,int)> qpow=[&](int a,int x){
        int res=1;
        while(x){
            if(x&1) res=res*a%q;
            a=a*a%q;
            x>>=1;
        }
        return res;
    };
    int ans=qpow(base,n-1)*f[n]%q;
    base--;odd--;
    while(odd>=1){
        ans=(ans+qpow(base,n-2)*f[n-2]%q)%q;
        base-=2,odd-=2;
    }
    cout<<ans-1<<"\n";
    return 0;
}