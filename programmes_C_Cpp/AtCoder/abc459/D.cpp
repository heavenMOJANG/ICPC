#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct info {
    char c; int f;
    bool operator < (const info &x) const { return f > x.f; }
};
void solve() {
    string S; cin >> S;
    int L = S.size();
    vector<int> cnt(26, 0);
    for (char c : S) cnt[c - 'a'] ++;
    vector<info> v;
    int MAXF{};
    for (int i{}; i < 26; ++ i)
        if (cnt[i]) v.push_back({char(i + 'a'), cnt[i]}), MAXF = max(MAXF, cnt[i]);
    if (MAXF > (L + 1) / 2) { cout << "No\n"; return; }
    sort(v.begin(), v.end());
    string ans(L, ' ');
    int idx{};
    for (const auto & [c, f] : v) {
        for (int i{}; i < f; ++ i) {
            if (idx >= L) idx = 1;
            ans[idx] = c;
            idx += 2;
        }
    }
    cout << "Yes\n" << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}
