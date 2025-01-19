#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+1),b(n+1),v(n+1,0);
    for(int i=1;i<n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    sort(++a.begin(),--a.end());
    sort(++b.begin(),b.end());
    int lst=0,cnt=0,ans=0,p;
    for(int i=1;i<n;++i){
        int l=lst+1,r=n,tag=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(b[mid]>a[i]) r=mid-1,tag=mid;
            else l=mid+1;
        }
        if(tag) cnt++,lst=tag,v[tag]=1;
        else break;
    }
    ans+=m*(n-cnt-1);
    for(int i=n;i;--i) if(!v[i]){p=i;break;}
    ans+=max(m-b[p]+1,0ll);
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
