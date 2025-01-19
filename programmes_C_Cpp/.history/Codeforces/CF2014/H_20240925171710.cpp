#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
mt19937_64 rnd(time(NULL));
vector<int> ref(N);
void solve() {
    
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    for (int i = 1; i < N; ++ i) ref[i] = rnd();
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}