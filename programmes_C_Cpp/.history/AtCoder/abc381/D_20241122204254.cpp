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
    for (int i = 0; i < n - 1; ++ i)
        if (a[i] == a[i + 1]) {
            cnt[a[i]] += 2;
            int len = 2;
            maxn = max(maxn, len);
            for (int j = i + 2; j < n - 1; j += 2) {
                if (a[j] == a[j + 1]) {
                    if (cnt[a[j]] != 0) {
                        for (int k = i; k < j; ++ k) cnt[a[i]] --;
                        i = j - 1;
                        break;
                    } else {
                        cnt[a[j]] += 2;
                        len += 2;
                        maxn = max(maxn, len);
                    }
                } else {
                    for (int k = i; k < j; ++ k) cnt[a[i]] --;
                    i = j;
                    break;
                }
            }
        }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}