#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+2,0),b(n+2);
    vector<pair<int,int>>q(n+2);
    for(int i=1;i<=n;++i) cin>>a[i],a[i]+=a[i-1];
    int m;cin>>m;
    while(m--){
        int l,u;cin>>l>>u;
        int ll=l,r=n;
        while(r-l>=50){
            int mid=(r-l+1)/3;
            int ml=l+mid,mr=r-mid;
            int t1=a[ml]-a[ll-1],t2=a[mr]-a[ll-1];
            t1=u*t1-(t1-1)*t1/2;
            t2=u*t2-(t2-1)*t2/2;
            if(t1<=t2)l=ml;
            else r=mr;
        }
        int maxn=-2e18,idx=0;
        for(int i=l;i<=r;i++){
            int t=a[i]-a[ll-1];
            t=u*t-(t-1)*t/2;
            if(t>maxn){
                maxn=t;
                idx=i;
            }
        }
        cout<<idx<<" ";
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
