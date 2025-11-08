#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int f(int x) {
    if (!x) return 0ll;
    int res{};
    while (x) {
        res += (x % 10);
        x /= 10;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n; ++ i)
        for (int j{}; j < i; ++ j) a[i] += f(a[j]);
    cout << a[n] << "\n"; 
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}