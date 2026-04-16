#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
unordered_map<int,int> memo;
int X;
int f(int a) {
    if (a < X) return 0;
    if (a < 2 * X) return 1;
    auto it = memo.find(a);
    if (it != memo.end()) return it->second;
    int left = a / 2;
    int right = a - left;
    return memo[a] = f(left) + f(right);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int need = (n + m + 1) / 2;

    auto check = [&](int x) -> bool {
        X = x;
        memo.clear();

        int cnt0 = 0;      // 初始 >= x 的棒子数
        int pos = 0;       // 最多能通过“有效切割”增加多少根
        int H = 0;         // 无害切割容量（来自 <x 的棒子）

        for (int v : a) {
            if (v >= x) cnt0++;
            int fv = f(v);
            if (fv > 0) pos += fv - 1;
            if (v < x) H += v - 1;
        }

        // s = 实际能做的有效切割次数
        int s = min(pos, m);
        int R = m - s;  // 剩余切割次数

        int final_cnt;
        if (R <= H) {
            // 剩余切割可以完全“消耗”在废料上
            final_cnt = cnt0 + s;
        } else {
            // 不够废料，只能破坏 >=x 的棒子
            final_cnt = cnt0 + s - (R - H);
        }

        return final_cnt >= need;
    };

    int l = 1, r = mx, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}