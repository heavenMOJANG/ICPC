#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e4 + 10;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    while (m --) {
        string y; cin >> y;
        bitset<N> s;
        for (int i = 0; i < y.size(); ++ i) s[i] = y[y.size() - 1 - i] - '0';
        
        for (int i = n; i; -- i) {
            bitset<N> t = s;
            if (a[i])
                for (int j = a[i]; j < k; ++ j) t[j] = t[j] ^ t[j - a[i]];
            else 
                for (int j = k - 1 + a[i]; ~j; -- j) t[j] = t[j] ^ t[j - a[i]];
            s = t;
        }
        int flag{};/*
        for (int i = k - 1; ~i; -- i) {
            if (s[i]) flag = 1;
            if (flag) cout << s[i];
        }
        if (!flag) cout << "0";
        cout << "\n";
        */
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}