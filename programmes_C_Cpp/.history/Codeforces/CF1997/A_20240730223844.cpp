#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    string s; cin >> s;
    if (s.size() == 1) cout << s << (s[0] - 1 + 'a') % 'a' + 'a' << "\n";
    int flag = 0;
    for (int i = 1; i < s.size(); ++ i) 
        if (s[i] == s[i - 1]) s.insert(char((s[0] - 1 + 'a') % 'a' + 'a'), i);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}