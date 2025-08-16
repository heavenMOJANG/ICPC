#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    string t = "";
    int flag = 1;
    for (auto ch : s)
        if (ch == '#') t += '#', flag = 1;
        else {
            if (flag) t += "o", flag = 0;
            else t += ".";
        }
    cout << t << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}