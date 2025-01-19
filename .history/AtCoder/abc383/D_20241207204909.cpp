#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e6 + 10;
int primes[N],isPrime[N],idx;
void Euler_Sieve(){
    for(int i=2;i<=x;++i){
        if(!isPrime[i]) primes[idx++]=i;
        for(int j = 0;j < idx && i * primes[j] < N; ++ j){
            isPrime[i * primes[j]]=1;
            if(i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int n; cin >> n;
    for ()
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}