#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;

int fastPow(int x, int y) {
    int res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

void solve() {
    int n; 
    cin >> n;
    vector<pair<int, int>> a;
    a.reserve(n * 6LL);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            int x; 
            cin >> x;
            a.emplace_back(x, i);
        }
    }
    sort(a.begin(), a.end());

    vector<int> inv(7);
    for (int i = 1; i <= 6; ++i)inv[i] = fastPow(i, MOD - 2);
    int inv6n = fastPow(inv[6], n);
    vector<int> cnt(n, 0);
    int cnt0 = n, res = 1, F = 0, ans = 0;

    int M = (int)a.size();
    int i = 0;
    while (i < M) {
        int v = a[i].first;
        int j = i;
        // process all faces equal to v
        while (j < M && a[j].first == v) {
            int d = a[j].second;
            int pre = cnt[d];
            int cur = pre + 1;
            cnt[d] = cur;
            if (pre == 0) {
                cnt0--;
                res = res * cur % MOD;
            } else {
                res = res * cur % MOD * inv[pre] % MOD;
            }
            j++;
        }
        int tmp = 0;
        if (cnt0 == 0) {
            tmp = (int)((long long)res * inv6n % MOD);
        }
        int d = (tmp - F + MOD) % MOD;
        ans = (ans + (long long)(v % MOD) * d % MOD) % MOD;
        F = tmp;
        i = j;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}
