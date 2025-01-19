#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
void solve() {
    string s; cin >> s;
    int k = 0, ans = 0;
    map<int, vector<int>> mp;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] == '0') k ++;
        else k --;
        for (auto && x : mp[k]) {
            ans += s.size() - (i - x) + 1;
        }
        m
    }
    cout<<s<<endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}