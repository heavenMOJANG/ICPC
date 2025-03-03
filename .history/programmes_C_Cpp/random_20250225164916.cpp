#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int MOD = 2e5;
constexpr int MAX = 1e9;
mt19937 rnd(time(0));
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("5.in", "w", stdout);
    vector<int> N;
    int sumN{};
    while (1) {
        int maxn = MOD - sumN;
        if (maxn <= 0) break;
        int n = (rnd() % maxn) + 1;
        if (sumN + n > MOD) break;
        N.push_back(n);
        sumN += n;
    }
    cout << N.size() << endl;
    for (int i = 0; i < N.size(); ++ i) {
        int k = rnd() % N[i] + 1;
        cout << N[i] << " " << k << endl;
        for (int j = 1; j <= N[i]; ++ j) {
            int x = rnd() % (MAX + 1), y = rnd() % (MAX + 1);
            int fx = rnd() & 1 ? 1 : -1, fy = rnd() & 1 ? 1 : -1;
            cout << x * fx << " " << y * fy << endl;
        }
    }
    fclose(stdout);
    return 0;
}
