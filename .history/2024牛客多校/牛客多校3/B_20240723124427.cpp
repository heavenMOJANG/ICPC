#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 110;
int n, D, h[N], d[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> D;
    for (int i = 0; i < n; ++ i) cin >> h[i];
    int minn = LLONG_MAX;
    vector<int> v;
    for (int i = 0; i < n; ++ i) {
        if (h[i] <= D) v.emplace_back(h[i]);
        else minn = min(minn, h[i] - D);
    }
    int gcd = LLONG_MAX;
    if (!v.empty()) {
        int gcd = v[0];
        for (int i = 1; i < v.size(); ++ i) gcd = __gcd(gcd, v[i]);
    }
    cout << min(minn, D % gcd) << "\n";
    return 0;
}