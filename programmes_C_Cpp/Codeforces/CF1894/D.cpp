#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,m,a[200010],b[200010],f[200010],d[200010],c[200010],cnt;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) d[i]=INT_MAX,f[i]=0;
    cnt=0;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    sort(b+1,b+1+m,greater<int>());
    d[1]=a[1];
    f[1]=1;
    int len=1;
    for(int i=2;i<=n;++i){
        int l=1,r=len,tag=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(d[mid]<a[i]) l=mid+1,tag=mid;
            else r=mid-1;
        }
        d[tag+1]=min(d[tag+1],a[i]);
        len=max(len,tag+1);
        f[i]=tag+1;
    }
    int pos=0;
    for(int i=n;i;--i) if(f[i]>f[pos]) pos=i;
    for(int i=1;i<=n;++i)
        if (f[i]==f[pos]) c[++cnt]=a[i];
    c[++cnt]=0;
    int pp=1,now=1;
    while (b[pp]>=c[now]&&pp<=m) cout<<b[pp++]<<" ";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
        if(f[i]==f[pos]) now++;
        while (b[pp]>=c[now]&&pp<=m) cout<<b[pp++]<<" ";
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
