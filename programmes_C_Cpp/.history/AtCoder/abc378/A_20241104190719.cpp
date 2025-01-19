#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    map<int, int> mp;
    for (int i = 0, x; i < 4; ++ i) cin >> x, mp[x] ++;
    int ans{};
    for (auto [x, y] : mp) if(y == 2 || y == 3) ans ++; else if (y == 4) ans += 2;
    cout << ans << "\n"; 
    return 0;
}