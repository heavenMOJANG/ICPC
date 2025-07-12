#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 998244353;

int64 modmul(int64 a, int64 b){
    return ( __int128(a) * b ) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 N;
    cin >> N;

    // 1) Compute T = sum_{i=1}^N floor(N/i)  in O(sqrt(N))
    int64 T = 0;
    int64 i = 1;
    while (i <= N) {
        int64 q = N / i;
        int64 r = N / q;         // maximal j such that floor(N/j) == q
        int64 cnt = (r - i + 1) % MOD;
        T = (T + modmul(q % MOD, cnt)) % MOD;
        i = r + 1;
    }

    // 2) Compute N*(N+1)/2 mod
    int64 half = (MOD + 1) / 2;
    int64 NN1 = modmul(N % MOD, (N + 1) % MOD);
    int64 total = modmul(NN1, half);

    // 3) Answer = total - T  (mod MOD)
    int64 ans = (total - T) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << "\n";

    return 0;
}
