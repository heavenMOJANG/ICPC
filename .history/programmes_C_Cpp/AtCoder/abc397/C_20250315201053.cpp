#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 3e5 + 10;
int cnt[N], rec[N];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    cnt[a[0]] = 1, rec[a[0]] = 1;
    for (int i = 1; i < n; ++ i) {
        cnt[a[i]] ++;
        if (cnt[a[i]] == 1) rec[i] = rec[i - 1] + 1;
        else rec[i] = rec[i - 1]; 
    }
    int maxn{};
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}