#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    map<char, int> mp;
    string s; cin >> s;
    for (auto ch : s) mp[ch]++;
    for (auto [ch, cnt] : mp)
        if (cnt == 1) {
            cout << ch << "\n";
            break;
        }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}