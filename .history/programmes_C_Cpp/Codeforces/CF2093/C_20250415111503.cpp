#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e6 + 10;
int notPrime[N], primes[N], idx;
bool check(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    for (int i = 2; i <= sqrt(x); ++ i) if (x % i == 0) return 0;
return 1;l
}
void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        cout << (notPrime[n] ? "NO\n" : "YES\n");
    }
    else {
        if (n != 1) { cout << "NO\n"; return; }
        else {
            int temp{};
            for (int i{}; i < k; ++ i) temp = temp * 10 + 1;
            cout << (notPrime[temp] ? "NO\n" : "YES\n");
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}