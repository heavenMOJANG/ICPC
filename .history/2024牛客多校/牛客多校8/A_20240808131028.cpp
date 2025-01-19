#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int isPrime[N], primes[N], idx;
void getPrimes() {
    fill(isPrime, isPrime + N, 1);
    isPrime[1] = 0;
    for (int i = 2; i < N; ++ i) {
        if (isPrime[i]) primes[idx ++] = i;
        for (int j = 0; j < idx && i * primes[j] < N; ++ j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
}
int fastPow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a;
        a = a * a;
        x >>= 1;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> h;
    for (int i = 0; i < n; ++ i) cin >> a[i], h[a[i]] = 1;
    if (n == 1) {cout << "Haitang\n"; return;}
    int gcd = a[0];
    for (int i = 1; i < n; ++ i) gcd = __gcd(gcd, a[i]);
    int ans = 0;
    if (gcd == 1) ans ++;
    map<int, vector<int>>
    for (int i = 0; i < n; ++ i) {
        int tmp = a[i], p = 0;
        while (tmp != 1) {
            int k = 0;
            while (tmp % primes[p] == 0) tmp /= primes[p], k ++;
            //b[primes[p]][k] ++;
            p ++;
        }
    }/*
    for (int i = 0; i < idx; ++ i) {
        int flag = 0;
        for(int j = 16; j >= 0; -- j) {
            if (b[primes[i]][j] == 1) {
                if (flag && h[fastPow(primes[i], j)] != 1) ans ++;
                flag = 1;
            }
            if (b[primes[i]][j] >= 2) {
                if (h[fastPow(primes[i], j)] != 1) {
                    ans ++;
                    flag = 1;
                }
            }
            if (h[fastPow(primes[i], j)] == 1) flag = 1;
        }
    }*/
    cout << ans << "\n";
    cout << (ans & 1 ? "dXqwq\n" : "Haitang\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}