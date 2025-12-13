#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e9;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    int N = 2e5, Q = 2e5;
    cout << N << "\n";
    for (int i{}; i < N; ++ i) cout << rnd() % MOD + 1 << " \n"[i == N - 1];
    cout << Q << "\n";
    for (int i{}; i < Q; ++ i) {
        int op = rnd() & 1;
        if (op == 0) {
            int c = rnd() % N + 1;
            cout << "1 " << c << "\n";
        } else {
            int l = rnd() % N + 1;
            int r = rnd() % N + 1;
            if (l > r) swap(l, r);
            cout << "2 " << l << " " << r << "\n";
        }
    }
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
