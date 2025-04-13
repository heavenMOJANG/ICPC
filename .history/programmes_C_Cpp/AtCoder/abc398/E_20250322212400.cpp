#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector a(n + 1, vector<int> (n + 1, 0));
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        a[u][v] = a[v][u] = 1;
    }
    set<int> black, white;
    white.insert(1);
    function<void(int, int, int)> dfs = [&](int u, int fa, int clr) {
        for (auto v : g[u]) {
            if (v == fa) continue;
            if (!clr) black.insert(v);
            else white.insert(v);
            dfs(v, u, clr ^ 1);
        }
    };
    dfs(1, 0, 0);
    int sum = (int)black.size() * (int)white.size() - (n - 1);
    cout << sum << "\n";
    if (sum & 1) {
        cout << "First" << endl;
        for (auto x : black)
            for (auto y : white) {
                if (!a[x][y]) {
                    a[x][y] = 1;
                    cout << x << " " << y << endl;
                }
                break;
            }
        int ax, ay;
        while (cin >> ax >> ay && ax != -1) {
            a[ax][ay] = 1;
            for (auto x : black)
                for (auto y : white) {
                    if (!a[x][y]) {
                        a[x][y] = 1;
                        cout << x << " " << y << endl;
                    }
                    break;
                }
        }
    } else {
        cout << "Second" << endl;
        int ax, ay;
        while (cin >> ax >> ay && ax != -1) {
            a[ax][ay] = 1;
            for (auto x : black)
                for (auto y : white) {
                    if (!a[x][y]) {
                        a[x][y] = 1;
                        cout << x << " " << y << endl;
                    }
                    break;
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