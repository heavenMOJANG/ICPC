#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<pair<int, int>, int> mp;
    int x{}, y{};
    mp[{x, y}] = 1;
    char flag = 'S';
    for (int i = 0; i < n; ++ i) {
        switch (s[i]) {
            case 'L':
                x --; mp[{x, y}] ++; break;
            case 'R':
                x ++; mp[{x, y}] ++; break;
            case 'S':
                y ++; mp[{x, y}] ++; break;
        }
    }
    for (auto [i, j] : mp) if (j > 2) {cout << "-1\n"; return;}
    if (mp[{0, 0}] != 2) {cout << "0\n"; return;}
    cout << "1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}