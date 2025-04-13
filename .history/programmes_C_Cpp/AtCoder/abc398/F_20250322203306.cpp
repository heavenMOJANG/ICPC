#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string t; cin >> t;
    string s = t;
    reverse(s.begin(), s.end());
    string str = s + "#" + t;
    int n = str.size();
    vector<int> pi(n, 0);
    int maxn{};
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) j = pi[j - 1];
        if (str[i] == str[j]) j++;
        pi[i] = j;
        maxn = max(maxn, pi[i]);
    }
    cout << t;
    for (int i = (maxn == 0 ? 1 : maxn * 2); i < n; ++ i) cout << s[i];
    //cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}