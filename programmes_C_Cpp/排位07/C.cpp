#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void write(__int128 n){
    if(n<0){putchar('-');n*=-1;}
    static __int128 sta[256];
    __int128 top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
void solve(){
    vector<vector<__int128>>dp(30,vector<__int128>(30,0));
    dp[1][0]=1;
    for(int i=2;i<=21;++i)
        for(int j=0;j<i;++j){
            dp[i][j]=dp[i-1][j];
            if(j) dp[i][j]+=dp[i-1][j-1]*(i-1);
        }
    int n,k;
    while(cin>>n>>k&&n) write(dp[n][k]),puts("");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
