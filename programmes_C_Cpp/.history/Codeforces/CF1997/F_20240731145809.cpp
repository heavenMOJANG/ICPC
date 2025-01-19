#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 55000;
int n, x, m, dp[1010][N + 10], fib[25];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> x >> m;
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 24; ++ i) fib[i] = fib[i - 1] + fib[i - 2];

    return 0;
}