#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int l=0,r=n-1,ans=0;
    while(l<=r){
        if(!k) break;
        int tmp=min(a[l],a[r]);
        if(k<2*tmp) break;
        else{
            k-=2*tmp;
            if(a[l]>a[r]){
                r--;
                ans++;
            }
            else if(a[l]==a[r]){
                l++,r--;
                ans+=2;
            }
            else{
                l++;
                ans++;
            }
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