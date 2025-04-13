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
int ok;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), c(n + 1), pre(n + 1, 0);
    int nn = n - n % 3;
    for (int i = 1; i <= nn; i += 3) {
        vector<int> v = {i, i + 1, i + 2};
        do {
            int ok{};
            for (int j = 0; j < 3; ++ j) {
                a[i + j] = v[j];
                pre[i + j] = pre[i + j - 1] + a[i + j];
                c[i + j] = (a[i + j] + i + j - 1) / (i + j);
                if (!isPrime[c[i + j]]) ok ++;
            }
            if (ok) break;
        } while(next_permutation(v.begin(), v.end()));
        cout << a[i] << " " << a[i + 1] << " " << a[i + 2] << " ";
    }
    for (int i = nn + 1; i <= n; ++ i) a[i] = i;/*
    int cnt{};
    for (int i = 1; i <= n; ++ i) {
        a[i] += a[i - 1];
        c[i] = (a[i] + i - 1) / i;
        if (!isPrime[c[i]]) ++ cnt;
    }
    cout << cnt << "\n";*/
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}