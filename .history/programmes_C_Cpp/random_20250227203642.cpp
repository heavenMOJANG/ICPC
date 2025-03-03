#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 3e5;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("9.in", "w", stdout);
    int n = N, m = rnd() % N;
    cout << n << " " << m << endl;
    for (int i = 1; i <= m; ++ i) {
        int u = rnd() % n + 1, v = rnd() % n + 1;
        if (u == v) v ++;
        cout << u << " " << v << endl;
    }
    fclose(stdout);
    return 0;
}
