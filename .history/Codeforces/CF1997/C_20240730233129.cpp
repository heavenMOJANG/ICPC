#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        if (s[i] == '(') stk.push(i);
        if (s[i] == '_') {
            if (s[stk.top()] == '(') {
                ans += i - stk.top();
                stk.pop();
            } else stk.push(i);
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