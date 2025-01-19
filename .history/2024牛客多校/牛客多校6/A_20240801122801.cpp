#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s;cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> cnt3(n + 1, 0), cntu(n + 1, 0);
    int flag = 1;
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == '3') cnt3[i] = 1, cnt3[i] += cnt3[i - 1];
        if (s[i] == '5') {
            cntu[i] = 1, cntu[i] += cntu[i - 1];
            if (!flag) {cout << "invalid\n"; return;}
            else flag = 0;
        }
        if (s[i] == 'U') {
            pre[3][i] ++, pre[3][i] += pre[3][i - 1];
            flag = 1;
        }
        if (i > 10) {
            if (pre[0][i] - pre[0][i - 10] == 10) {cout << "invalid\n"; return;}
        }
        if (i > 90) {
            if (pre[2][i] - pre[2][i - 90] == 0 && pre[3][i] - pre[3][i - 90] == 0) {cout << "invalid\n"; return;}
        }
        
    }
    cout << "valid\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}