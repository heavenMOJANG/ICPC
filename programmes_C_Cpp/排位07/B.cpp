#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>f(60);
    int n,t;
    while(cin>>n>>t){
        f[0]=1;
        for(int i=1;i<=n;++i) f[i]=f[i-1]*t;
        int s1=0,s2=0;
        for(int i=1;i<=n;++i) s1+=f[__gcd(i-1,n)];
        if(n&1) s2=n*f[n/2+1];
        else s2=n*(f[(n-2)/2+2]+f[n/2])/2;
        cout<<s1/n<<" "<<(s1+s2)/n/2<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
