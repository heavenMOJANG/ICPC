#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
const int N=3e3+10;
struct node
{
    int id,num;
}a[N];
bool cmp(node x,node y)
{
    return x.num<y.num;
}
int b[N];
struct data
{
    int l,r;
}c[N];
map<int,int> mp;
void solve() {
    mp.clear();
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        c[i].l=n+10,c[i].r=0;
    }
    for(int i=1;i<=n;i++) cin>>a[i].num;
    sort(a+1,a+1+n,cmp);
    int cnt=1;
    a[1].id=1;
    mp[a[1].num]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i].num!=a[i-1].num)
        {
            cnt++;
            mp[a[i].num]=cnt;
        }
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
            int mid_num=(a[i].num+a[j].num+1)/2;
            int mid=mp[mid_num];
            if(mp[mid_num]==0) continue;
            int idx=i+j>>1;
            int l=c[mid].l,r=c[mid].r;
            if(l<=idx&&r>=idx)
            {
                if(j-i+1>ans)
                {
                    ans=j-i+1;
                    //cout<<i<<' '<<j<<'\n';
                }
            }
            else
            {
                int res=min(c[mid].r-i+1,j-c[mid].l+1);
                if(res*2>ans)
                {
                    ans=res*2;
                    //cout<<i<<' '<<j<<'\n';
                }
            }
        }
    }
    cout<<ans<<'\n';
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}