#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int l=0,r=n-1,x=0,ans=0;
    while(l<=r){
        if(l==r){
            if((a[l]-x)&1){
                ans+=(a[l]-x)/2;
                if(x+(a[l]-x)/2>0) ans++;
                ans++;
            }
            else ans+=(a[l]-x)/2+1;
            break;
        }
        int t=min(a[r]-x,a[l]);
        a[l]-=t,ans+=t,x+=t;
        if(a[l]==0)l++;
        if(a[r]==x){
            a[r]-=x;
            x=0;
            r--;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
