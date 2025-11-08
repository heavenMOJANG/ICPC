#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int EPS = 1e-15L;
double f(double a, double b, double c, double L, double R){
    if(R < L) return numeric_limits<double>::infinity();
    double res = numeric_limits<double>::infinity();
    res = min(res, a*L*L + b*L + c);
    res = min(res, a*R*R + b*R + c);
    if(fabsl(a) < EPS) return res;
    else {
        double t0 = -b / (2 * a);
        if (t0 >= L - EPS && t0 <= R + EPS) res = min(res, a*t0*t0 + b*t0 + c);
        return res;
    }
}
void solve() {
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}