#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 2e5 + 10;
int cnt, primes[N], isPrime[N];
void getPrime() {
    fill(isPrime, isPrime + N, 1);
    isPrime[1] = isPrime[0] = 0;
    for (int i = 2; i < N; ++ i) {
        if (isPrime[i]) primes[cnt++] = i;
        for (int j = 0; j < cnt && primes[j] * i < N; ++ j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    int l = 0,r = 0;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (a[i] < 0) l += a[i];
        else r += a[i];
    }
    set<pair<int, int>> s;
    function<int(int, int, int)> isValid = [&](int sum, int p, int x) {
        for (auto it = s.begin(); it != s.end(); ++ it) {
            if (sum - it -> first < x) return 0;
            if (isPrime[p - it -> second]) return 1;
        }
        return 0;
    };
    function<int(int)> check = [&](int x) {
        for (int i = 1, res = 1; res <= k; ++ i) {
            if (i > n) return 0;
            s.clear();
            s.insert({0, i - 1});
            for (int j = 0; ; ++ i) {
                if (i > n) return 0;
                j += a[i];
                if (isValid(j ,i, x)) {i ++; break;}
                s.insert({j, i});
            }
        }
        return 1;
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrime();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}