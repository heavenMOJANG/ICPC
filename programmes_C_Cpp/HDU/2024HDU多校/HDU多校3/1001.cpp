#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int mod = 998244353;
int n;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        (f[i] += (f[i - 1]  + 1) % mod) % mod;
            for(int j = 2; i * j <= n; ++ j)
                f[i * j] = (f[i * j] + f[i - 1]) % mod;
    }
    for (int i = 1; i <= n; ++ i) cout << f[i] << " \n"[i == n];
    return 0;
}