#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,dp[210][2],f[210][2];
vector<ll>e[210];
map<string,ll>mp;
string s1,s2;
void dfs(ll u){
    dp[u][0]=0;dp[u][1]=1;
    for(auto v:e[u]){
        dfs(v);
        if(dp[v][0]==dp[v][1]){
            dp[u][0]+=dp[v][0];
            f[u][0]=0;
        }
        else if(dp[v][0]>dp[v][1]){
            dp[u][0]+=dp[v][0];
            if(!f[v][0]) f[u][0]=0;
        }
        else{
            dp[u][0]+=dp[v][1];
            if(!f[v][1]) f[u][0]=0;
        }
        dp[u][1]+=dp[v][0];
        if(!f[v][0]) f[u][1]=0;
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n){
        mp.clear();
        for(ll i=0;i<=n;++i) e[i].clear();
        memset(f,1,sizeof(f));
        ll k=1;
        cin>>s1;
        mp[s1]=k++;
        e[0].push_back(mp[s1]);
        for(ll i=1;i<n;++i){
            cin>>s1>>s2;
            if(mp[s1]==0) mp[s1]=k++;
            if(mp[s2]==0) mp[s2]=k++;
            e[mp[s2]].push_back(mp[s1]);
        }
        dfs(0);
        cout<<dp[0][0]<<" "<<(f[0][0]?"Yes\n":"No\n");
    }
    return 0;
}
