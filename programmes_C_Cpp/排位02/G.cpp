#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;
    while(cin>>n){
        vector<int>a(n),s(n,0);
        int sum=0;
        for(int i=0;i<n;++i) cin>>a[i],sum+=a[i];
        int avg=sum/n;
        for(int i=0;i<n;++i) s[i]=s[i-1]+a[i]-avg;
        sort(s.begin(),s.end());
        int mid=s[n/2];
        int ans=0;
        for(int i=0;i<n;++i) ans+=llabs(s[i]-mid);
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
