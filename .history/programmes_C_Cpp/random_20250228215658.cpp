#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5;
constexpr int K = 5e3;
constexpr int S = 100;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("1.in", "w", stdout);
    int n = rnd() % N + 1, k = rnd() % K + 1, s = rnd() % (S + 1);
    cout << n << " " << k << " " << s << endl;
    for (int i = 1; i <= n; ++ i) {
        int a = rnd() % (S + 1), b = rnd() % (S + 1);
        cout << a << " " << b << endl;
    }
    fclose(stdout);
    return 0;
}
