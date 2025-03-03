#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define random(a,b) (rand()%(b-a+1))+a
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int MOD = 3e5;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));
signed main(){
    //cin.tie(0)->ios::sync_with_stdio(0);
    int N = rnd() % MOD + 1;
    freopen("1.in","w",stdout);
    cout << N << "\n";
    while (N) {
        int n = rnd() % N + 1;
        cout << n << " " << n << "\n";
        for (int i = 1; i <= n; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == n];
        for (int i = 1; i <= n; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == n];
        for (int i = 1; i <= n; ++ i) {
            int l = rnd() % n + 1, r = rnd() % n + 1;
            if (l > r) swap(l, r);
            cout << l << " " << r << "\n";
        }
        N -= n;
    }
    fclose(stdout);
    return 0;
}
