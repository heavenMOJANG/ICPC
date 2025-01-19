#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    string t = s;
    for (auto ch : t)
        if ('a' <= ch && ch <= 'z') ch -= 32;
        else ch += 32;
    int n = s.size();
    vector<char> ans;
    int q; cin >> q;
    while (q --) {
        int x; cin >> x;
        if (x <= n) ans.emplace_back(s[x - 1]);
        else {

        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}