#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<pair<int, int>, int> mp;
    int x{}, y{};
    char flag = 'U';
    char flag0 = s[0];
    if (flag0 == 'S') flag0 = 'U';
    for (int i = 0; i < n; ++ i) {
        switch (s[i]) {
            case 'L' :
                if (flag == 'L') flag = 'D';
                else if (flag == 'R') flag = 'U';
                else if (flag == 'U') flag = 'L';
                else if (flag == 'D') flag = 'R';
                break;
            case 'R' :
                if (flag == 'L') flag = 'U';
                else if (flag == 'R') flag = 'D';
                else if (flag == 'U') flag = 'R';
                else if (flag == 'D') flag = 'L';
                break;
            case 'S':break;
        }
        switch (flag) {
            case 'L' : x --; break;
            case 'R' : x ++; break;
            case 'U' : y ++; break;
            case 'D' : y --; break;
        }
        //cout << x << " " << y << "\n";
        mp[{x, y}] ++;
    }
    for (auto [i, j] : mp) if (j > 1) {cout << "-1\n"; return;}
    if ((x != 0 || y != 0) || flag != 'U') {cout << "0\n"; return;}
    cout << "1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}