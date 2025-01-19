#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int res=0;
    for(int i=0;i<n;++i){
        int j=i;
        while(j+1<n&&a[j+1]==a[j]) j++;
        int t=j-i+1;
        res=(res+t*t%mod)%mod;
        i=j;
    }
    function<void(int,int,int)>solve=[&](int l,int r,int dep)->void
    {
        if(dep<0||l>r) return;
        int pos=l-1;
        while(pos+1<=r&&!(a[pos+1]>>dep&1)) pos++;
            int c1=pos-l+1,c2=r-pos;
            res=(res+c1*c2%mod*3%mod)%mod;
            res=(res+c2*c2%mod)%mod;
            solve(l,pos,dep-1);
            solve(pos+1,r,dep-1);
    };    
    solve(0,n-1,29);
    cout<<res/n/n<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
