#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> pos;
    for (int i = 1; i < s.size() - 1; ++ i)
        if (s[i] == '/') {
            if (s[i - 1] != '/') pos.emplace_back(i);
        }
    int maxn = 1;
    for (auto p : pos) {
        int l = p - 1, r = p + 1, tmp = 1;
        while (s[l] == '1' && s[r] == '2' && l >= 0 && r < s.size())
            l --, r ++, tmp += 2;
        maxn = max(maxn, tmp);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}