#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e7;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    cout << "10000\n";
    for (int t{}; t < 10000; ++ t) {
        int a = rnd() % 100 + 1, b = rnd() % 100 + 1;
        int x = rnd() % MOD + 1, y = rnd() % MOD + 1;
    }
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
