#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e18;
void solve() {
    string X, Y; cin >> X >> Y;
    int Q; cin >> Q;
    vector<int> l = {0ll, X.length(), Y.length()};
    vector<array<int, 26>> cnt(3);
    for (char c : X) cnt[1][c - 'a'] ++;
    for (char c : Y) cnt[2][c - 'a'] ++;
    while (l.back() < N) {
        int n = l.size();
        l.emplace_back(min(N, l[n - 1] + l[n - 2]));
        vector<int> res{};
        for (int c{}; c < 26; ++ c) res[c] = min(N, cnt[n - 1][c] + cnt[n - 2][c]);
        cnt.emplace_back(res);
    }
    function<int(int, int, char)> cal = [&](int n, int p, char c) {
        if (p <= 0) return 0ll;
        if (n == 1) {
            p = min(p, X.length());
            int res{};
            for (int i{}; i < p; ++ p) res += (X[i] == c);
            return res;
        }
        if (n == 2) {
            p = min(p, Y.length());
            int res{};
            for (int i{}; i < p; ++ p) res += (Y[i] == c);
            return res;
        }
        if (p <= len[n - 1]) return cal(n - 1, p, c);
        return cnt[n - 1][c - 'a'] + cal(n - 2, p - len[n - 1], c);
    };
    int m = len.size() - 1;
    while (Q --) {
        int L, R; cin >> L >> R;
        char C; cin >> C;
        cout << cal(m, R, C) - cal(m, L - 1, C) << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}