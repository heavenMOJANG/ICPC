#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>f,id(x+1,-1);
    int k=0;
    for(int i=1;i*i<=x;++i)
        if(x%i==0){
            id[i]=k++;
            f.emplace_back(i);
            if(i*i!=x){
                id[x/i]=k++;
                f.emplace_back(x/i);
            }
        }
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;++i){
        int j=i;
        vector<int>dp(k);
        dp[0]=1;
        if(x%a[i]==0) dp[id[a[i]]]=1;
        while(j+1<=n&&(x%a[j+1]!=0||!dp[id[x/a[j+1]]])){
            j++;
            vector<int>ndp=dp;
            for(int t=0;t<k;++t){
                if(!dp[t]) continue;
                if(x%(a[j]*f[t])==0) ndp[id[a[j]*f[t]]]=1;
            }
            dp.swap(ndp);
        }
        ans++;
        i=j;
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