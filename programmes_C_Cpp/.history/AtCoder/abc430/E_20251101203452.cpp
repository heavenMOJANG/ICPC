#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string A, B; cin >> A >> B;
    int n = A.size();
    array<int, 2> ca = {0,0}, cb = ca;
    for (char c : A) ca[c - '0'] ++;
    for (char c : B) cb[c - '0'] ++;
    if (ca != cb) { cout << -1 << '\n'; return; }
    string pat = B, txt = A + A;
    int m = pat.size(), nn = txt.size();
    vector<int> p(m);
    p[0] = 0;
    for (int i = 1; i < m; ++ i) {
        int j = p[i - 1];
        while (j && pat[i] != pat[j]) j = p[j - 1];
        if (pat[i] == pat[j]) ++ j;
        p[i] = j;
    }
    int j{}, ans = -1;
    for (int i{}; i < nn; ++ i) {
        while (j > 0 && txt[i] != pat[j]) j = p[j - 1];
        if (txt[i] == pat[j]) ++j;
        if (j == m) {
            int start = i - m + 1;
            if (start < n) { ans = start; break; }
            j = p[j - 1];
        }
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}