#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int n=s.size();
    reverse(s.begin(),s.end());
    vector<int>v;
    for(int i=0;i<n;++i)
        if(s[i]=='0') v.push_back(i);
    auto qpow=[&](int a,int x){
        int res=1;
        while(x){
            if(x&1) res=res*a%mod;
            a=a*a%mod;
            x>>=1;
        }
        return res;
    };
    int A=qpow(3,n),B=0;
    for(int i=0;i<v.size();++i) B=(B+qpow(3,v[i])*qpow(2,i)%mod)%mod;
    cout<<A<<" "<<B<<"\n";
    int ans=(A-B+mod)%mod;
    cout<<ans<<"\n";
    return 0;
}
