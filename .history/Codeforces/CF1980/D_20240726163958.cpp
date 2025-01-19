#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < n - 1; ++ i) b[i] = __gcd(a[i], a[i + 1]);
    if (n == 3) {cout << "YES\n"; return;}
    map<int, int> mp;
    for (int i = 0; i < n - 2; ++ i)
        if (b[i] > b[i + 1]) mp[i] ++;
    if(mp.size() == 0) {cout << "YES\n"; return;}
    int flag = 0;
    for (int i = 0; i < n; ++ i) {
        if (i == 0) {
            if (b[i] > b[i + 1] && mp.size() == 1) flag = 1;
        } else if (i == n - 1) {
            if (b[i - 2] > b[i - 1] && mp.size() == 1) flag = 1;
        }
    } else {
        int g
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}