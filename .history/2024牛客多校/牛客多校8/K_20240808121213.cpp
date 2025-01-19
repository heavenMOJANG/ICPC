#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    while(s.substr(0, 3) == "ava") {
        if (s.substr(0, 5) == "avava") {
            s.erase(0, 5);
            continue;
        }
        if (s.substr(0, 3) == "ava") s.erase(0, 3);
    }
    reverse(s.begin(), s.end());
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}