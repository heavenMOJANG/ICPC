#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>f(15,0),dp(15,0);
    f[0]=1;
    for(int i=1;i<15;++i) dp[i]=i*f[i-1],f[i]=f[i-1]*10;
    int m,n;
    while(cin>>m>>n,m+n>=0){
        vector<int>num(15,0);
        int cntm[15],cntn[15];
        memset(cntm,0,sizeof cntm);
        memset(cntn,0,sizeof cntn);
        function<void(int,int*)> dfs=[&](int x,int*cnt){
            int len=0;
            while(x){
                num[++len]=x%10;
                x/=10;
            }
            for(int i=len;i>=1;--i){
                for(int j=0;j<=9;++j) cnt[j]+=dp[i-1]*num[i];
                for(int j=0;j<num[i];++j) cnt[j]+=f[i-1];
                int tmp=0;
                for(int j=i-1;j>=1;--j) tmp=tmp*10+num[j];
                cnt[num[i]]+=tmp+1;
                cnt[0]-=f[i-1];
            }
        };
        if(m) dfs(m-1,cntm);
        else cntm[0]=-1;
        if(n) dfs(n,cntn);
        else cntn[0]=0;
        cout<<cntn[0]-cntm[0]<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
