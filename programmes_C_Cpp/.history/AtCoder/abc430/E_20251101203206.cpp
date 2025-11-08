#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string pat, txt; cin >> pat >> txt;
    int m = pat.size(), n = txt.size();
    vector<int> p(m);
    p[0] = 0;
    for (int i = 1; i < m; ++ i) {
        int j = p[i - 1];
        while (j && p[i] != p[j]) j = p[j - 1];
        if (p[i] == p[j]) ++ j;
        p[i] = j;
    }
    auto kmp = [&](int lmt) {
        if (!m) return 0ll;
        int j{};
        for (int i{}; i < n; ++ i) {
            while (j && txt[i] != pat[j]) j = p[j - 1];
            if (txt[i] == pat[j]) ++ j;
            if (j == m) {
                int start = i - m + 1;
                if (start < lmt) return start;
                j = p[j - 1];
            }
        }
        return -1ll;
    };
    array<int, 2> cp = {0, 0}, ct = cp;
    for (char c : pat) cp[c - '0'] ++;
    for (char c : txt) ct[c - '0'] ++;
    string tt = pat + pat;
    cout << kmp(n) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}