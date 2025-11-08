#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
double min_on_interval(double a, double b, double c, double L, double R){
    if(R < L) return numeric_limits<double>::infinity();
    double res = numeric_limits<ld>::infinity();
    // 端点
    res = min(res, a*L*L + b*L + c);
    res = min(res, a*R*R + b*R + c);
    if(fabsl(a) < EPS){
        // 退化为线性或常数，端点已检查
        return res;
    } else {
        ld t0 = -b / (2*a);
        if(t0 >= L - 1e-15L && t0 <= R + 1e-15L){
            res = min(res, a*t0*t0 + b*t0 + c);
        }
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