#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e9;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    cout << "1000\n";
    int n = rnd() % 28 + 2, c = rnd()% MOD + 1;
    cout << n << " " << c << "\n";
    for (int i{}; i < n; ++ i) cout << rnd() % MOD + 1 << " \n"[i == n - 1];
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
