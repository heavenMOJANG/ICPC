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
    int flag = 1, cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; ++ i) {
        if (s[i] == '3') cnt3 ++, cnt4 ++;
        if (s[i] == '4') cnt3 = 0, cnt4 ++;
        if (cnt3 == 10 || cnt4 == 90) {cout << "invalid\n"; return;}
        if (s[i] == '5') {
            cnt3 = cnt4 = 0;
            if (!flag) {cout << "invalid\n"; return;}
            else flag = 0;
        }
        if (s[i] == 'U') {
            cnt3 = cnt4 = 0;
            flag = 1;
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