#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 110;
int n, D, h[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> D;
    for (int i = 0; i < n; ++ i) cin >> h[i];
    int gcd = h[0];
    for (int i = 1; i < n; ++ i) gcd = __gcd(gcd, h[i]);
    cout << D % gcd << "\n";
    return 0;
}