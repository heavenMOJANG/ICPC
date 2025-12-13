#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e9;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    cout << "1000\n";
    for (int t = 1; t <= 1000; ++ t) {
        int n = 40; cout << n << "\n";
        for (int i = 1; i <= n; ++ i) cout << rnd() % 41 << " \n"[i == n];
    }
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
