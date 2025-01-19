#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e6 + 10;
int primes[N], isPrime[N], idx;
void euler(int x){
    for(int i = 2; i <= x; ++ i){
        if (!isPrime[i]) primes[idx ++]=i;
        for(int j = 0; j < idx && i * primes[j] <= x; ++ j) {
            isPrime[i * primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    euler(N - 10);
    string s; int p;
    cin >> s >> p;
    if (p == 1) { cout << "0\n"; return 0; }
    if (s >= "1000000") { cout << "0\n"; return 0; }
    int maxn{}, pp = p, n = stoi(s);
    idx = 0;
    while (pp != 1) {
        while (pp % primes[idx] == 0) pp /= primes[idx], maxn = max(maxn, primes[idx]);
        idx ++;
    }
    if (n >= maxn) { cout << "0\n"; return 0; }
    int res = 1;
    for (int i = 2; i <= n; ++ i) res = res * i % p;
    cout << res << "\n";
    return 0;
}