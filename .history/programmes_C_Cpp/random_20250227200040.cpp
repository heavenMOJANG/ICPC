#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 3e5;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("10.in", "w", stdout);
    int n = 1e5, m = 1e5, q = 1e5;
    cout << n << " " << m << " " << q << endl;
    for (int i = 1; i <= n; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == n];
    for (int i = 1; i <= m; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == m];
    for (int i = 1; i <= q; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == q];
    fclose(stdout);
    return 0;
}
