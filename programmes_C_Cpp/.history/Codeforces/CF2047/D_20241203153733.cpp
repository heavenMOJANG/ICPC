#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, queue<int>> r;
    for (int i = 0; i < n; ++ i) cin >> a[i], r[a[i]].push(i);
    int pre = -1, p = n;
    for (auto it = r.begin(); it != r.end(); ++ it) {
        while (!it->second.empty()) {
            if (it->second.front() > pre) {
                pre = it->second.front();
                cout << it->second.front() << " ";
                it->second.pop();
            } else {
                r[it->first + 1].push(p ++);
                it->second.pop();
            }
        }
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}