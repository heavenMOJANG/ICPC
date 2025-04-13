#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    stack<int> s0, s1;
    int x; cin >> x;
    s0.push(x);
    int maxn{}, cnt{};
    for (int i = 1; i < n; ++ i) {
        cin >> x;
        if (!s0.empty() && x < s0.top()) s0.push(x);
        else {
            if (s1.empty() || x > s1.top()) s1.push(x);
            else {
                maxn = max(maxn, (int)s0.size());
                cnt ++;
                while (!s0.empty()) s0.pop();
                s0 = s1; s0.push(x);
                while (!s1.empty()) s1.pop();
            }
        }
    }
    if (s0)
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}