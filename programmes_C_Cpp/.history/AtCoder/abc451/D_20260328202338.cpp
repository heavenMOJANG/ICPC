#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int LMT = 1e9;
void solve() {
    int N; cin >> N;
    vector<int> ans;
    vector<pair<int, int>> b;
    int p = 1;
    while (p <= LMT) {
        int mul = 1, tmp = p;
        while (tmp) {
            mul *= 10;
            tmp /= 10;
        }
        b.emplace_back(p, mul);
        p <<= 1;
    }
    function<void(int)> dfs = [&](int cur) {
        ans.emplace_back(cur);
        for (auto [fi, se] : b) {
            int nxt = cur * se + fi;
            if (nxt > LMT) break;
            dfs(nxt);
        }
    };
    for (auto [fi, se] : b) if (fi <= LMT) dfs(fi);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans[N - 1] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}