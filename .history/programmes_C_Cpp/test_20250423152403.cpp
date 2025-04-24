#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    queue<pair<string, int>> q;
    for (int i{}; i < 8; ++ i) {
        string id; int sc;
        cin >> id >> sc;
        q.push({id, sc});
    }
    for (int i{}; i < 6; ++ i) {
        auto [t0, s0] = q.front(); q.pop();
        auto [t1, s1] = q.front(); q.pop();
        if (s0 > s1) q.push({t0, s0});
        else q.push({t1, s1});
    }
    {
        auto [t0, s0] = q.front(); q.pop();
        auto [t1, s1] = q.front(); q.pop();
        if (s0 > s1) cout << t0 << " beats " << t1 << "\n";
        else cout << t1 <<  " beats " << t0 << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}