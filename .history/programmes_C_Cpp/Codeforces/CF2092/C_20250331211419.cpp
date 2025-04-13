#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> odd, even;
    for (int i{}, x; i < n; ++ i) {
        cin >> x;
        if (x & 1) odd.emplace_back(x);
        else even.emplace_back(x);
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());
    int maxOdd{}, maxEven;
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}