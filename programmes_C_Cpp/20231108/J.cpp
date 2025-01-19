#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int digits[12],dp[12][10010][2],k;
int dfs(int pos,int state,int limit){
    if(pos==-1) return state==0?1:0;
    if(!limit&&dp[pos][state][limit]!=-1) return dp[pos][state][limit];
    int up=limit?digits[pos]:9,ans=0;
    for(int i=0;i<=up;++i) ans+=dfs(pos-1,(state+i)%k,limit&&i==up);
    if(!limit) dp[pos][state][limit]=ans;
    return ans;
}
int solve(int x){
    int pos=0;
    while(x){
        digits[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,0,1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int _=1;cin>>_;
    while(_--){
        int a,b;cin>>a>>b>>k;
        if(k>=90){cout<<"0\n";continue;}
        cout<<solve(b)-solve(a-1)<<"\n";
    };
    return 0;
}
