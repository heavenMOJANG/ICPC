#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
bool v[1e6+10];
int a[1e6+10],b[1e6+10];
void solve() {
    int n,m; cin>>n>>m;
    for(int i=0;i<n*m;i++) v[i]=false;
    bool flag=true;
    int cnt=1;
    for(int i=1;i<=n*m;i+=m) a[cnt++]=i;
    cnt=0;
    for(int i=1;i<=n*m;i+=n) b[cnt++]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int num=a[i]*b[j]%(n*m);
            if(v[num])
            {
                flag=false;
                break;
            }
            v[num]=true;
        }
    }
    if(flag)
    {
        cout<<"Yes"<<'\n';
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=m;i++) cout<<b[i]<<' ';
        cout<<'\n';
    }
    else
    {
        cout<<"No"<<'\n';
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}