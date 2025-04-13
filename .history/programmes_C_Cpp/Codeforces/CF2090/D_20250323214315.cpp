#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int idx, primes[N], isPrime[N];
void getPrimes() {
    for (int i = 2; i < N; ++ i) {
        if (!isPrime[i]) primes[idx ++] = i;
        for (int j = 0; j < idx && i * primes[j] < N; ++ j) {
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 1; i <= n; ++ i) s.insert(i);
    int sum{};
    for (int i = 1; i <= n; ++ i) {
        int x = *s.begin();
        int cur = (sum + x - 1) / i + 1;
        while (isPrime[cur]) ++ cur;
        int tmp = i * (cur - 1) + 1 - sum;
        auto it = s.lower_bound(tmp);
        if (it == s.end()) it --;
        x = *it;
        sum += x;
        s.erase(x);
        cout << x << " ";
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}