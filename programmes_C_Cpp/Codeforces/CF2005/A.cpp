#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr char c[] = {'a', 'e', 'i', 'o', 'u'};
void solve() {
    int n; cin >> n;
    int k = n / 5, r = n % 5;
    for (int i = 0; i < 5; ++ i) {
        for (int j = 0; j < k; ++ j) cout << c[i];
        if (r) {cout << c[i]; r --;}
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