#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s;
    int pre = 0, flag = 1;
    for (int i = 1; i <= n; ++ i) {
        cin >> s;
        if (s == "sweet") pre = 1;
        else pre = 0;
        if (s == "sweet" && pre == 1) flag == 0;
    }
    cout << (flag ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}