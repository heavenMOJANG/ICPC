#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector preY(n + 10, 0), preYE(n + 10, 0), preN(n + 10, 0);
    int YES{}, NO{};
    for (int i = 1; i <= n; ++ i) {
        preY[i] = preY[i - 1];
        preYE[i] = preYE[i - 1];
        preN[i] = preN[i - 1];
        switch (s[i]) {
            case 'Y':
                preY[i] ++;
                break;
            case 'E':
                preYE[i] += preY[i - 1];
                break;
            case 'S':
                YES += preYE[i];
                break;
            case 'N':
                preN[i] ++;
                break;
            case 'O':
                NO += preN[i - 1];
                break;
        }
    }
    cout << YES << " " << NO << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}