#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    sort(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0ll);
    set<int> ans;
    int l1 = a.back();
    auto check = [&](int x) {
        int l{}, r = n - 1;
        while (l <= r) {
            if (a[r] == x) r --;
            else {
                if (l >= r) return false;
                if (a[l] + a[r] != x) return false;
                l ++, r --;
            }
        }
        return true;
    };
    if (check(l1)) ans.insert(l1);
    if (n % 2 == 0 && 2 * sum % n == 0) {
        int l2 = 2 * sum / n;
        if (l2 >= a.back() && check(l2)) ans.insert(l2);
    }
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}