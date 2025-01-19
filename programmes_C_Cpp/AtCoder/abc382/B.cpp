#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, d; cin >> n >> d;
    string s; cin >> s;
    vector<int> p;
    for (int i = n - 1; i >= 0; -- i) if (s[i] == '@') p.emplace_back(i);
    for (int i = 0; i < d; ++ i) s[p[i]] = '.';
    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}