#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    int tot = N * (N + 1) / 2;
    auto get = [&](char x, char y, const string& s, int n) -> int {
        vector<int> f(n << 1 | 1, 0);
        int cur{};
        f[cur + n] = 1;
        int p{};
        for (char c : s) {
            if (c == x) cur ++;
            else if (c == y) cur --;
            p += f[cur + n];
            f[cur + n] ++;
        }
        return p;
    };
    int ab = get('A', 'B', S, N);
    int bc = get('B', 'C', S, N);
    int ca = get('C', 'A', S, N);
    vector<pair<int, int>> pre(N + 1);
    int caCnt{}, cbCnt{}, ccCnt{};
    pre[0] = {0, 0};
    for (int i{}; i < N; ++ i) {
        if (S[i] == 'A') caCnt ++;
        else if (S[i] == 'B') cbCnt ++;
        else if (S[i] == 'C') ccCnt ++;
        pre[i + 1] = {caCnt - cbCnt, cbCnt - ccCnt};
    }
    sort(pre.begin(), pre.end());
    int abc{}, cur = 1;
    for (int i = 1; i <= N; ++ i)
        if (pre[i] == pre[i - 1]) cur ++;
        else abc += cur * (cur - 1) / 2, cur = 1;
    abc += cur * (cur - 1) / 2;
    int ans = tot - ab - bc - ca + 2 * abc;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}