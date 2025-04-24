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
    vector<int> row(n);
    for (int i{}; i < m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            string s; cin >> s;
            if (s[0] == '-') {
                s.erase(0, 1);
                int x = stoi(s);
                sex[x] = 0;
                row[j] = x;
            } else {
                int x = stoi(s);
                sex[x] = 1;
                row[j] = x;
            }
        }
        for (int a{}; a < k; ++ a)
            for (int b{}; b < k; ++ b) if (sex[a] != sex[b]) g[a][b] += 1.0 / k, g[b][a] += 1.0 / k;
    }
    int A, B; cin >> A >> B;
    double maxA{}, maxB{};
    for (int i{}; i < n; ++ i) if (sex[i] != sex[A]) maxA = max(maxA, g[i][A]);
    for (int i{}; i < n; ++ i) if (sex[i] != sex[B]) maxB = max(maxB, g[i][B]);
    if (g[A][B] == maxA) {
        if (!sex[A]) cout << "-"; cout << abs(A) << " ";
        if (!sex[B]) cout << "-"; cout << abs(B) << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}