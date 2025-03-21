#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s, t = "^"; cin >> s;
    for (auto ch : s) t += "#", t += ch;
    t += "#", t += "@";
    vector<int> p(t.size() + 1, 0);
    int R = 0, mid = 0;
    for (int i = 1; i < str.size() - 1; i++) {
        P[i] = R > i ? min(P[2 * mid - i], R - i) : 1;	//进行三种情况的判断
        while (str[i + P[i]] == str[i - P[i]]) P[i]++;	//中心拓展
        if (i + P[i] > R) {                           	//如果当前回文串已经覆盖到了原先没有覆盖到的地方，则更新标记
            R = i + P[i];
            mid = i;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}