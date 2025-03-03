#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int MOD = 3e5;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));

signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("13.in", "w", stdout);
    vector<int> N, Q;
    int sumN{}, sumQ{};
    while (1) {
        int n = rnd() % MOD + 1, q = rnd() % MOD + 1;
        if (sumN + n > MOD || sumQ + q > MOD) break;
        N.push_back(n), Q.push_back(q);
        sumN += n, sumQ += q;
    }
    cout << N.size() << "\n";
    for (int k = 0; k < N.size(); ++ k) {
        cout << N[k] << " " << Q[k] << "\n";
        for (int i = 1; i <= N[k]; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == N[k]];
        for (int i = 1; i <= N[k]; ++ i) cout << rnd() % (MAX + 1) << " \n"[i == N[k]];
        for (int i = 1; i <= Q[k]; ++ i) {
            int l = rnd() % N[k] + 1, r = rnd() % N[k] + 1;
            if (l > r) swap(l, r);
            cout << l << " " << r << "\n";
        }
    }
    fclose(stdout);
    return 0;
}
