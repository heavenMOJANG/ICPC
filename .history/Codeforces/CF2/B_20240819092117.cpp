#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector dp(n + 1, vector (n + 1, vector<int> (2)));
    vector path(n + 1, vector (n + 1, vector<char> (2)));
    int flag = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j =)
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}