#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n, l; cin >> n >> l;
    vector<string> s(n);
    for (auto && x : s) cin >> x;
    auto init = [&](vector<string> s) {
        vector<int> ok(n, 0);
        for (int i{}; i < n; ++ i)
            for (int j{}; j < n; ++ j) {
                if (i == j) continue;
                if (s[j].find(s[i]) != string::npos) { ok[i] = 1; break; }
            }
        vector<string> res;
        for (int i{}; i < n; ++ i) if (!ok[i]) res.emplace_back(s[i]);
        return res;
    };
    s = init(s);
    n = s.size();
    if (!n) {
        int ans = 1;
        for (int i{}; i < l; ++ i) (ans *= 26) %= MOD;
        cout << ans << "\n";
        return;
    }
    vector<vector<int>> trie;
    vector<int> fail, endp;
    int idx = 1;
    trie.emplace_back(26, 0);
    fail.emplace_back(0);
    endp.emplace_back(0);
    for (int i{}; i < n; ++ i) {
        int p{};
        for (char c : s[i]) {
            if (trie[p][c - 'a'] == 0) {
                trie[p][c - 'a'] = idx ++;
                trie.emplace_back(26, 0);
                fail.emplace_back(0);
                endp.emplace_back(0);
            }
            p = trie[p][c - 'a'];
        }
        endp[p] |= 1ll << i;
    }
    queue<int> q;
    for (int c{}; c < 26; ++ c) if (trie[0][c]) q.push(trie[0][c]);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int c{}; c < 26; ++ c) {
            if (trie[u][c]) {
                fail[trie[u][c]] = trie[fail[u]][c];
                endp[trie[u][c]] |= endp[fail[trie[u][c]]];
                q.push(trie[u][c]);
            } else trie[u][c] = trie[fail[u]][c];
        }
    }
    vector dp(idx, vector<int> (1ll << n, 0));
    dp[0][0] = 1;
    for (int k{}; k < l; ++ k) {
        vector ndp(idx, vector<int> (1ll << n, 0));
        for (int u{}; u < idx; ++ u)
            for (int mask{}; mask < (1ll << n); ++ mask) {
                if (!dp[u][mask]) continue;
                for (int c{}; c < 26; ++ c) {
                    int v = trie[u][c], maskv = mask | endp[v];
                    (ndp[v][maskv] += dp[u][mask]) %= MOD;
                }
            }
        dp.swap(ndp);
    }
    int ans{};
    for (int i{}; i < idx; ++ i) (ans += dp[i][(1ll << n) - 1]) %= MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}