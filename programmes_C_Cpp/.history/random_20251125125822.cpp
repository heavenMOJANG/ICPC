#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e9;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    int a = rnd() % (MOD - 1) + 1, b = rnd() % (MOD - 1) + 1;
    while (a == 1 || b == 1 || __gcd(a, b) != 1) {
        a = rnd() % (MOD - 1) + 1;
        b = rnd() % (MOD - 1) + 1;
    }
    cout << a << " " << b << "\n";
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
