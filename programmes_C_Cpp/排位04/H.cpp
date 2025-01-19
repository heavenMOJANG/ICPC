#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
const int fac[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void solve(){
    int a,b,k;cin>>a>>b>>k;
    if(k>90){cout<<"0\n";return;}
    vector<vector<vector<int>>>dp(15,vector<vector<int>>(100,vector<int>(100,-1)));
    function<int(int,int,int)> dfs=[&](int d,int x1,int x2){
        if(d==0) return dp[d][x1][x2]=(x1+x2==0)?1:0;
        if(dp[d][x1][x2]!=-1) return dp[d][x1][x2];
        int res=0;
        for(int i=0;i<=9;++i)
            res+=dfs(d-1,((x1-i)%k+k)%k,((x2-i*fac[d-1])%k+k)%k);
        return dp[d][x1][x2]=res;
    };
    function<int(int)> sum=[&](int x)->int{
        if(x==0) return 1;
        int tmp=x,sz=0;
        vector<int>b(15,0);
        while(tmp){
            b[sz++]=tmp%10;
            tmp/=10;
        }
        int res=0,s1=0,s2=0;
        for(int i=sz-1;i>=0;--i){
            if(i)
                for(int j=0;j<b[i];++j) res+=dfs(i,(k-(s1+j)%k)%k,(k-(s2+j*fac[i])%k)%k);
            else
                for(int j=0;j<=b[i];++j) res+=dfs(i,(k-(s1+j)%k)%k,(k-(s2+j*fac[i])%k)%k);
            s1+=b[i];
            s2+=b[i]*fac[i];
        }
        return res;
    };
    cout<<sum(b)-sum(a-1)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
