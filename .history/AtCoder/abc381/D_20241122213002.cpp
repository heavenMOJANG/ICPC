#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int cnt[200010];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int maxn{};
    vector<int> b0, b1;
    for (int i = 0; i + 1 < n; i += 2)
        if (a[i] == a[i + 1]) b0.emplace_back(a[i]);
        else b0.emplace_back(-1);
    for (int i = 1; i + 1 < n; i += 2)
        if (a[i] == a[i + 1]) b1.emplace_back(a[i]);
        else b1.emplace_back(-1);
    int l = 0, r = 0;
    while (r < b0.size()) {
        cnt[b0[r]] ++;
        if (cnt[b0[r]] == 2) {
            while (cnt[b0[r]] == 2) {
                cnt[b0[l]] --;
                l ++;
            }
        }
        maxn = max(maxn, (r - l + 1) * 2);
        r ++;
    }
    if (cnt[b0[r]] == 2) {
        while (cnt[b0[r]] == 2) {
            cnt[b0[l]] --;
            l ++;
        }
    }
    maxn = max(maxn, (r - l + 1) * 2);
    l = 0, r = 0;
    while (r < b1.size()) {
        cnt[b1[r]] ++;
        if (cnt[b1[r]] == 2) {
            while (cnt[b1[r]] == 2) {
                cnt[b1[l]] --;
                l ++;
            }
        }
        maxn = max(maxn, (r - l + 1) * 2);
        r ++;
    }
    if (cnt[b1[r]] == 2) {
        while (cnt[b1[r]] == 2) {
            cnt[b1[l]] --;
            l ++;
        }
    }
    maxn = max(maxn, (r - l + 1) * 2);
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}