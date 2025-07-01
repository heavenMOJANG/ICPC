#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p(n + 1, 0);
    p[n] = n;
    for (int i = n - 1; ~i; -- i)
        if (s[i] < s[p[i + 1]]) p[i] = i;
        else if (s[i] > s[p[i + 1]]) p[i] = p[i + 1];
        else p[i] = p[p[i + 1] + 1];
    cout << s.substr(0, p[0]) + s.substr(p[0]) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}