#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    string s; cin >> s;
    
    int flag = 0;
    for (int i = 1; i < s.size(); ++ i) 
        if (s[i] == s[i - 1]) {
            if (s[i] == 'a') s.insert(i, "b");
            else s.insert(i, "a");
        }
    if (!flag) {
        if (s[0] == 'a') s.insert(0, "b");
        else s.insert(0, "a");
    }

    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}