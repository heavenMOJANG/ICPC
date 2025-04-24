#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> sex(n);
    vector<vector<double>> g(n, vector<double>(n, 0.0));
    for (int i{}; i < m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            string s; cin >> s;
            if (s[0] == '-') {
                s.erase(0, 1);
                int x = stoi(s);
                sex[x] = 0;
            } else {
                int x = stoi(s);
                sex[x] = 1;
            }
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