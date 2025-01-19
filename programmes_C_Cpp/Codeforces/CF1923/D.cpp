#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+2),s(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    vector<int>pre(n+2),suf(n+2);
    for(int i=2;i<=n;++i)
        if(a[i]==a[i-1]) pre[i]=pre[i-1];
        else pre[i]=i-1;
    suf[n]=n+1;
    for(int i=n-1;i>=1;--i)
        if(a[i]==a[i+1]) suf[i]=suf[i+1];
        else suf[i]=i+1;
    for(int i=1;i<=n;++i){
        int ans=inf;
        if(s[i-1]>a[i]){
            int l=0,r=i-1;
            while(l<r){
                int mid=(l+r+1)/2;
                if(s[i-1]-s[mid-1]>a[i]) l=mid;
                else r=mid-1;
            }
            if (r==i-1) ans=min(ans,1ll);
            else if(pre[i-1]!=0)
                    ans=min(ans,max(i-r,i-pre[i-1]));
        }
        if(s[n]-s[i]>a[i]){
            int l=i+1,r=n;
            while(l<r){
                int mid=(l+r)/2;
                if (s[mid]-s[i]>a[i]) r=mid;
                else l=mid+1;
            }
            if(r==i+1) ans=min(ans,1ll);
            else if(suf[i+1]!=n+1) ans=min(ans,max(r-i,suf[i+1]-i));
        }
        if(ans==inf) ans=-1;
        cout<<ans<<" ";
    }
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
