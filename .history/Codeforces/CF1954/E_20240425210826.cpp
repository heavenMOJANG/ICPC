#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int m =*max_element(all(a));
    vv<int> ans(m + 2);
    per(i, 2, n)
    {
        int x = a[i] - 1, y = a[i - 1] - 1;
        if(x <= y) continue;
        for(int l = 1, r; l <= m; l = r + 1)
        {
            r = min(x / l == 0 ? m : x / (x / l), y / l == 0 ? m : y / (y / l));
            ans[l] += x / l - y / l, ans[r + 1] -= x / l - y / l;
        }
    }
    per(i, 1, m)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] + (a[1] + i - 1) / i << ' ';
    }
    cout << endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}