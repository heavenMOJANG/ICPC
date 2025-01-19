#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
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
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrime(1e6);
    cin >> n;
    if (n == 4) {cout << "5\n"; return 0;}
    int ans = 0;
    for (int i = 2; i <= sqrt(n); ++ i) {
        ans += (n / i - 1) * i;
        if (n / i > sqrt(n)) {
            int p = sqrt(n) + 1;
            int q = n / i;
            ans += (q - p + 1) * (q + p) / 2;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++ i) if (vis[i]) cnt ++;
    cout << ans + cnt << "\n";
    return 0;
}