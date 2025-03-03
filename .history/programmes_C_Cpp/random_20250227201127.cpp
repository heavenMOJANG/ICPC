#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 3e5;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("8.in", "w", stdout);
    int n = 3e5, q = rnd() % MAX + 1;
    cout << n << " " << q << endl;
    for (int i = 1; i <= n; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == n];
    fclose(stdout);
    return 0;
}
