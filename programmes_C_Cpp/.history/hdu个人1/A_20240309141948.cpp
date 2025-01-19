#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
char s[2000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s+1;
    auto qpow=[&](int a,int x){
        int res=1;
        while(x){
            if(x&1) res=res*a%mod;
            a=a*a%mod;
            x>>=1;
        }
        return res;
    };
    int ans=qpow(3,s.size()-1);
    int tmp=1;
    for(int i=0;i<s.size();++i)
        if(s[i]=='1') tmp=tmp*3%mod;
    ans=(ans+tmp)%mod;
    cout<<ans<<"\n";
    return 0;
}
