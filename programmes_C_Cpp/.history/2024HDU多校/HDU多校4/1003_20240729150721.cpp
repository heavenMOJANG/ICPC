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
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    function<int(int)> check = [&](int x) {
        int res = 0, sum = 0, cnt = 0;
        for (int i = 0; i < n; ++ i) {
            if (sum >= x) {
                if (isPrime[cnt]) {
                    sum = 0;
                    cnt = 0;
                    res ++;
                } else {
                    sum += a[i];
                    cnt ++;
                }
            } else {
                sum += a[i];
                cnt ++;
            }
        }
        if (sum >= x) {
            if (isPrime[cnt]) {
                sum = 0;
                cnt = 0;
                res ++;
            } else return false;
        } else return false;
        return res == k;
    };
    int l = -2e8, r = 2e8;
    while (l < r) {
        int mid = l + r >> 1;
        cout << mid << "\n";
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    if (l == -2e8) cout << "impossible\n";
    else cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrime();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}