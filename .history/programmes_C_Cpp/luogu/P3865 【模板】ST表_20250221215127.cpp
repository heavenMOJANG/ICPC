#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 +10;
int n,m, fac[N],a[N],dp[N][22];
void init(){
    for(int i = 1;i <= n; ++ i) dp[i][0]=a[i];
    int t = fac[n];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j + (1ll << i) <= n + 1; ++ j)
            dp[j][i] = max(dp[j][i - 1], dp[j + (1ll << (i - 1))][i - 1]);
}
int query(int l, int r){
    int t = fac[r - l + 1];
    return max(dp[l][t], dp[r - (1ll << t) + 1][t]);
}
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    fac[1] = 0;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i / 2] + 1;
    cin>>n>>m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    init();
    while (m --) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << "\n";
    }
    return 0;
}