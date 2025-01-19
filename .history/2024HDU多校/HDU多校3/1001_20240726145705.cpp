#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int mod = 998244353;
int n,prime[1000010],vis[1000010],idx;
void getPrime(int x){
    memset(vis,1,sizeof(vis));
    vis[1] = 0;
    for(int i = 2; i <= x; ++ i){
        if(vis[i]) prime[idx ++ ] = i;
        for (int j = 0;j < idx && i * prime[j] <= x; ++ j) {
            vis[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrime(1e6);
    cin >> n;
    vector<int> f(n + 1, 0);
    f[1] = 1; f[2] = 2; f[3] = 3;
    for (int i = 2; 2 * i <= n; ++ i) f[2 * i] += 2;
    f[4] = 5;
    for (int i = 5; i <= n; ++ i) {
        if (vis[i]) f[i] = (f[i - 1] + 1) % mod;
        else if (vis[i - 1]) f[i] = (f[i] + f[i - 2]) % mod;
        if (2 * i <= n) {
            for (int j = 2; i * j <= n; ++ j)
                f[i * j] = (f[i * j] + i) % mod;
        }
    }
    for (int i = 1; i <= n; ++ i) cout << f[i] << " \n"[i == n];
    return 0;
}