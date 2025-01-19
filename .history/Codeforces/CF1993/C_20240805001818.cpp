#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end());
    set<int> s;
    for (int i = 0; i < n; ++ i) b[i] = a[i] % (2 * k), s.insert(b[i]);
    if (s.size() == 1) {cout << a[n - 1] << "\n"; return;}
    vector<int> c; int m;
    for(auto x : s) c.emplace_back(x), m++;
    int l = *s.begin(), r = *(--s.end());
    for (auto it = s.begin(); it != (--s.end()); ++ it) {
        if (r - l < k) {
            cout << a[n - 1] + r - b[n - 1] << "\n";
            return;
        } else {
            auto rear = it; ++ rear;
            l = *rear, r = *it + 2 * k;
        }
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}