#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int MOD = 2e5;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("2.in", "w", stdout);
    vector<int> N;
    int sumN{};
    while (1) {
        int maxn = MOD - sumN;
        if (maxn <= 0) break;
        int n = (rnd() % maxn);
        if (sumN + n > MOD) break;
        N.push_back(n);
        sumN += n;
    }
    cout << N.size() << endl;
    for (int k = 0; k < N.size(); ++ k) {
        cout << N[k] << " " << Q[k] << endl;
        for (int i = 1; i <= Q[k]; ++ i) {
            int l = (rnd() % N[k]) + 1, r = (rnd() % N[k]) + 1;
            if (l > r) swap(l, r);
            cout << l << " " << r << endl;
        }
    }
    fclose(stdout);
    return 0;
}
