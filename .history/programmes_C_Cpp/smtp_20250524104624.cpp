#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
coonst int N=3e3+10;
struct node
{
    int id,num;
}a[N];
bool cmp(node x,node y)
{
    return x.num<y.num;
}
int b[N];
stuct data
{
    int l,r;
}c[N];
void solve() {
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        c[i].l=n+10,c[i].r=0;
    }
    for(int i=1;i<=n;i++) cin>>a[i].num;
    sort(a+1,a+1+n,cmp);
    int cnt=1;
    a[1].id=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i].num!=a[i-1].num) cnt++;
        a[i].id=cnt;
    }
    for(int i=1;i<=n;i++) b[i]=a[i].id;
    for(int i=1;i<=n;i++)
    {
        int num=b[i];
        c[num].l=min(c[num].l,i);
        c[num].r=max(c[num].r,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            int mid=b[i]+b[j]>>1;
            if(c[mid].r==0) continue;
            int idx=i+j>>1;
            if(l<=idx&&r>=idx) ans=max(ans,j-i+1);
            else
            {
                int res=min(c[mid].r-i,j-c[mid].l);
                ans=max(ans,res);
            }
        }
    }
    cout<<ans<<'\n';
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}