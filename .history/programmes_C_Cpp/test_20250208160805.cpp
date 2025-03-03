#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string g[3];
    cin >> g[0] >> g[1] >> g[2];
    auto check = [&](int x, int y) { return g[x][y] == 'X' || g[x][y] == 'G'; };
    if (g[0][0] == 'X') {
        if (check(0, 1) && check(0, 2)) { cout << "Yes\n"; return; }
        if (check(1, 0) && check(2, 0)) { cout << "Yes\n"; return; }
        if (check(1, 1) && check(2, 2)) { cout << "Yes\n"; return; }
    }
    if (g[0][1] == 'X') {
        if (check(0, 0) && check(0, 2)) { cout << "Yes\n"; return; }
        if (check(1, 1) && check(2, 1)) { cout << "Yes\n"; return; }
    }
    if (g[0][2] == 'X') {
        if (check(0, 0) && check(0, 1)) { cout << "Yes\n"; return; }
        if (check(1, 2) && check(2, 2)) { cout << "Yes\n"; return; }
        if (check(1, 1) && check(2, 0)) { cout << "Yes\n"; return; }
    }
    if (g[1][0] == 'X') {
        if (check(0, 0) && check(2, 0)) { cout << "Yes\n"; return; }
        if (check(1, 1) && check(1, 2)) { cout << "Yes\n"; return; }
    }
    if (g[1][1] == 'X') {
        if (check(1, 0) && check(1, 2)) { cout << "Yes\n"; return; }
        if (check(0, 1) && check(2, 1)) { cout << "Yes\n"; return; }
        if (check(0, 0) && check(2, 2)) { cout << "Yes\n"; return; }
        if (check(0, 2) && check(2, 0)) { cout << "Yes\n"; return; }
    }
    if (g[1][2] == 'X') {
        if (check(0, 2) && check(2, 2)) { cout << "Yes\n"; return; }
        if (check(1, 0) && check(1, 1)) { cout << "Yes\n"; return; }
    }
    if (g[2][0] == 'X') {
        if (check(0, 0) && check(1, 0)) { cout << "Yes\n"; return; }
        if (check(2, 1) && check(2, 2)) { cout << "Yes\n"; return; }
        if (check(1, 1) && check(0, 2)) { cout << "Yes\n"; return; }
    }
    if (g[2][1] == 'X') {
        if (check(2, 0) && check(2, 2)) { cout << "Yes\n"; return; }
        if (check(0, 1) && check(1, 1)) { cout << "Yes\n"; return; }
    }
    if (g[2][2] == 'X') {
        if (check(0, 0) && check(1, 1)) { cout << "Yes\n"; return; }
        if (check(2, 0) && check(2, 1)) { cout << "Yes\n"; return; }
        if (check(0, 2) && check(1, 2)) { cout << "Yes\n"; return; }
    }
    if (g[0][0] == 'G') {
        int res{};
        if ((check(0, 1) && check(0, 2)) res ++;
        if ((check(1, 0) && check(2, 0)) res ++;
        if ((check(1, 1) + check(2, 2))) res ++; 
        if (res >= 2) { cout << "Yes\n"; return; }
    }
    if (g[0][1] == 'G') {
        if ((check(0, 0) && check(0, 2)) + (check(1, 1) && check(2, 1)) >= 2) { cout << "Yes\n"; return; }
    }
    if (g[0][2] == 'G') {
        if ((check(0, 0) && check(0, 1)) + (check(1, 2) && check(2, 2)) + (check(1, 1) && check(2, 0)) >= 2) { cout << "Yes\n"; return; }
    }
    if (g[1][0] == 'G') {
        if ((check(0, 0) && check(2, 0)) + (check(1, 1) && check(1, 2)) >= 2) { cout << "Yes\n"; return; }
    }
    if (g[1][1] == 'G') {
        if ((check(0, 0) && check(2, 2)) + (check(0, 1) && check(2, 1)) + (check(0, 2) && check(2, 0)) + (check(1, 0) && check(1, 2)) >= 2) { cout << "Yes\n"; return; }
    }
    if (g[1][2] == 'G') {
        if ((check(1, 0) && check(1, 1)) + (check(0, 2) && check(2, 2)) >= 2) { cout << "Yes\n"; return; }
    }
    if (g[2][0] == 'G') {
        if ((check(0, 0) && check(1, 0)) + (check(2, 1) && check(2, 2)) + (check(1, 1) && check(0, 2)) >= 2) { cout << "Yes\n"; return; }
    }
    if (g[2][1] == 'G') {
        if ((check(2, 0) && check(2, 2)) + (check(1, 1) + check(0, 1)) >= 2) { cout << "Yes\n"; return; }
    }
    if (g[2][2] == 'G') {
        if ((check(2, 0) && check(2, 1)) + (check(0, 0) && check(1, 1)) + (check(1, 2) && check(0, 2)) >= 2) { cout << "Yes\n"; return; }
    }
    cout << "No\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}