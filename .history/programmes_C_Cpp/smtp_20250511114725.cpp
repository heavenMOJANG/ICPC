#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int n, a[N],b[N];
bool vis[N];
struct node
{
    int tar,len;
    bool flag;
}dp[N];
int ans;
int mx[N];
void dfs(int st)
{
    vis[st]=true;
    if(vis[a[st]])
    {
        dp[st].tar=a[st];
        dp[st].len=1;
        dp[st].flag=false;
        if(st==a[st]) ans+=1ll;
        return;
    }
    if(st>n)
    {
        dp[st].tar=st;
        dp[st].len=0;
        dp[st].flag=true;
        return;
    }
    dfs(a[st]);
    int nxt=a[st];
    dp[st].tar=dp[nxt].tar;
    dp[st].len=dp[nxt].len+1;
    dp[st].flag=dp[nxt].flag;
    int to=dp[nxt].tar;
    if(dp[st].flag) mx[to]=max(mx[to],dp[st].len);
    if(to==st) ans+=dp[st].len;
    return;
}
void solve() {
    ans=0;
    cin>>n;
    for(int i=1;i<=2*n;i++) vis[i]=false,mx[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        else
        {
            int to=a[i];
            if(vis[to])
            {
                vis[i]=true;
                if(dp[to].flag)
                {
                    dp[i].tar=dp[to].tar;
                    dp[i].len=dp[to].len+1;
                    mx[dp[i].tar]=max(mx[dp[i].tar],dp[i].len);
                    dp[i].flag=true;
                }
                else
                {
                    dp[i].tar=dp[to].tar;
                    dp[i].len=dp[to].len+1;
                    dp[i].flag=false;
                }
            }
            else dfs(i);
        }
    }
    for(int i=n+1;i<=2*n;i++) ans+=mx[i];
    cout<<ans<<'\n';
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}