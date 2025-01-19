#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=1e5+10;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(N),pre(N),suf(N);
    map<int,int>mp;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mp[a[i]%k]++;
    }
    sort(a.begin()+1,a.end(),[&](const int&a,const int&b){return a%k!=b%k?a%k<b%k:a<b;});
    int odd=0;
    for(auto [x,y]:mp) if(y&1) odd++;
    if(odd>=2){cout<<"-1\n";return;}
    int ans=0;
    for(int i=1;i<=n;++i){
        if(mp[a[i]%k]%2==0){
            for(int j=i+1;j<i+mp[a[i]%k];j+=2) ans+=(a[j]-a[j-1])/k;
            i+=mp[a[i]%k];
        }
        else{
            for(int j=i;j<=i+mp[a[i]%k];j+=2) pre[j]=(a[j+1]-a[j])/k;
            for(int j=i+mp[a[i]%k]-1;j>=i;j-=2) suf[j]=(a[j]-a[j-1])/k;
            for(int j=i;j<=i+mp[a[i]%k];++j) pre[j]+=pre[j-1];
            for(int j=i+mp[a[i]%k]-1;j>=i;--j) suf[j]+=suf[j+1];
            int num=suf[i+2];
            for(int j=i+2;j<=i+mp[a[i]%k];j+=2) num=min(num,pre[j-1]+suf[j+1]);
            for(int j=i+1;j<i+mp[a[i]%k];j+=2) num=min(num,pre[j-2]+suf[j-2]+(a[j+1]-a[j-1])/k);
            ans+=num;
            i+=mp[a[i]%k];
            fill(pre.begin(),pre.end(),0);
            fill(suf.begin(),suf.end(),0);
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}