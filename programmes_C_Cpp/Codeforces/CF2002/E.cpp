#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    deque<pair<int, int>> dq;
    int maxn = 0;
    for (int i = 1, a, b; i <= n; ++ i) {
        cin >> a >> b;
        if (dq.empty()) {
            dq.push_back({a, b});
            maxn = a;
            cout << maxn << " ";
            continue;
        }
        int aa = a, lst = 0;
        while(!dq.empty() && (dq.back().first <= a || dq.back().second == b)) {
            if (dq.back().second == b) {
                a -= lst;
                a += dq.back().first;
            } else lst = dq.back().first;
            aa = max(aa, a);
            dq.pop_back();
        }
        a = max(a, aa);
        if (dq.empty()) maxn = a;
        dq.push_back({a, b});
        cout << maxn << " ";
    }
    cout << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}