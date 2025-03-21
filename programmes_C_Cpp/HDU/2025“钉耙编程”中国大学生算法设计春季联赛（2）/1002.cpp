#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
const string x[] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
const string y[] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
map<string, int> mp;
void solve() {
    string s; cin >> s;
    cout << 1984 + mp[s] - 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int i{}, j{};
    for (int cnt = 1; cnt <= 60; ++ cnt) {
        mp[x[i] + y[j]] = cnt;
        i = (i + 1) % 10;
        j = (j + 1) % 12; 
    }
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}