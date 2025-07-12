#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n + 1, 0);
    for (int i{}; i < n; ++ i) cin >> a[i], pre[i + 1] = pre[i] + a[i];
    if (pre[n] & 1) { cout << "-1\n"; return; }
    int half = pre[n] / 2;
    for (int i = 1; i < n; ++ i)
        if (pre[i] == half) {
            cout << "1\n";
            for (int i{}; i < n; ++ i) cout << a[i] << " \n"[i == n - 1];
            return;
        }
    vector<int> val(n, -1), pos(n, -1);
    if (pre[1] < half) val[0] = pre[1], pos[0] = 1;
    for (int i = 1; i < n - 1; ++ i) {
        val[i] = val[i - 1];
        pos[i] = pos[i - 1];
        if (val[i] < pre[i + 1] && pre[i + 1] < half)
            val[i] = pre[i + 1], pos[i] = i + 1;
    }
    for (int p2 = 1; p2 < n; ++ p2) {
        if (pre[p2] > half && p2 > 1) {
            if (pos[p2 - 2] != -1) {
                int need = pre[p2] - half;
                if (val[p2 - 2] >= need) {
                    int p1 = pos[p2 - 2];
                    cout << "2\n";
                    vector<int> b1(n, 0), b2(n, 0);
                    int x = pre[p2] - half, tmp = x, res = x;
                    for (int i = p1; i < p2; ++ i) {
                        int d = min(a[i], res);
                        b1[i] = d, res -= d;
                    }
                    res = tmp;
                    for (int i{}; i < p1; ++ i) {
                        int d = min(a[i], res);
                        b1[i] = d, res -= d;
                    }
                    for (int i{}; i < n; ++ i) b2[i] = a[i] - b1[i];
                    for (int i{}; i < n; ++ i) cout << b1[i] << " \n"[i == n - 1];
                    for (int i{}; i < n; ++ i) cout << b2[i] << " \n"[i == n - 1];
                    return;
                }
            }
        }
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}