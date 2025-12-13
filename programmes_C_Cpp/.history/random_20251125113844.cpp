#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e9;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    int n = 200000;
    vector<int> t, a;
    for (int i{}; i < n; ++ i) {
        t.emplace_back((int)rnd() % (MOD - 1) + 1);
        a.emplace_back((int)rnd() % (MOD - 1) + 1);
    }
    sort(t.begin(), t.end());
    cout << n << "\n";
    for (int i{}; i < n; ++ i) cout << t[i] << " \n"[i == n - 1];
    for (int i{}; i < n; ++ i) cout << a[i] << " \n"[i == n - 1];
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
