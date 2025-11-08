#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr double EPS = 1e-18L;
double f(double a, double b, double c, double L, double R){
    if (R < L) return numeric_limits<double>::infinity();
    double res = numeric_limits<double>::infinity();
    res = min(res, a * L * L + b * L + c);
    res = min(res, a * R * R + b * R + c);
    if (fabsl(a) < EPS) return res;
    else {
        double x = -b / (2 * a);
        if (x >= L - 1e-15L && x <= R + 1e-15L) res = min(res, a * x * x + b * x + c);
        return res;
    }
}
void solve() {
    double TSx, TSy, TGx, TGy; cin >> TSx >> TSy >> TGx >> TGy;
    double ASx, ASy, AGx, AGy; cin >> ASx >> ASy >> AGx >> AGy;
    double dxT = TGx - TSx, dyT = TGy - TSy;
    double Tt = sqrtl(dxT * dxT + dyT * dyT);
    double vTx = dxT / Tt, vTy = dyT / Tt;
    double dxA = AGx - ASx, dyA = AGy - ASy;
    double Ta = sqrtl(dxA*dxA + dyA*dyA);
    double vAx = dxA / Ta, vAy = dyA / Ta;
    double minT = min(Tt, Ta);
    double maxT = max(Tt, Ta);
    double ans = numeric_limits<double>::infinity();
    {
        double d0x = TSx - ASx, d0y = TSy - ASy;
        double dx = vTx - vAx, dy = vTy - vAy;
        double a = dx * dx + dy * dy;
        double b = 2 * (d0x * dx + d0y * dy);
        double c = d0x * d0x + d0y * d0y;
        ans = min(ans, f(a, b, c, 0.0L, minT));
    }
    if(Tt < Ta){
        double d0x = TGx - ASx, d0y = TGy - ASy;
        double dx = -vAx, dy = -vAy;
        double a = dx * dx + dy * dy;
        double b = 2 * (d0x * dx + d0y * dy);
        double c = d0x * d0x + d0y * d0y;
        ans = min(ans, f(a,b,c, Tt, Ta));
    } else if(Ta < Tt){
        double d0x = TSx - AGx, d0y = TSy - AGy;
        double dx = vTx, dy = vTy;
        double a = dx * dx + dy * dy;
        double b = 2 * (d0x * dx + d0y * dy);
        double c = d0x * d0x + d0y * d0y;
        ans = min(ans, f(a, b, c, Ta, Tt));
    }
    {
        double fx = TGx - AGx, fy = TGy - AGy;
        double val = fx * fx + fy * fy;
        ans = min(ans, val);
    }
    cout << sqrt((double)ans) << "\n";
}
signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    cout.setf(std::ios::fixed); cout<<setprecision(15);
    while(_ --) solve();
    return 0;
}
