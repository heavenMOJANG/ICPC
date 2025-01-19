#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>f(13,1);
    for(int i=2;i<=12;++i) f[i]=f[i-1]*i;
    int n;
    while(cin>>n,n){
        map<int,int>cnt;
        int sum=f[n-1],tmp=0;
        for(int i=0,x;i<n;++i) cin>>x,cnt[x]++,tmp+=x;
        sum*=tmp;
        for(int i=0;i<10;++i) sum/=f[cnt[i]];
        int ans=0;
        for(int i=0;i<n;++i) ans=ans*10+sum;
        cout<<ans<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
