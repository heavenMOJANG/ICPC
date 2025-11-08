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
signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    int T;
    if(!(cin >> T)) return 0;
    cout.setf(std::ios::fixed); cout<<setprecision(15);
    while(T--){
        double TSx, TSy, TGx, TGy;
        double ASx, ASy, AGx, AGy;
        cin >> TSx >> TSy >> TGx >> TGy;
        cin >> ASx >> ASy >> AGx >> AGy;

        // times to reach
        double dxT = TGx - TSx, dyT = TGy - TSy;
        double Tt = sqrtl(dxT*dxT + dyT*dyT); // >0 by constraints
        double vTx = dxT / Tt, vTy = dyT / Tt;

        double dxA = AGx - ASx, dyA = AGy - ASy;
        double Ta = sqrtl(dxA*dxA + dyA*dyA);
        double vAx = dxA / Ta, vAy = dyA / Ta;

        double minT = min(Tt, Ta);
        double maxT = max(Tt, Ta);

        double best = numeric_limits<double>::infinity();

        // 1) both moving: t in [0, minT]
        {
            // delta0 = Ts - As
            double d0x = TSx - ASx, d0y = TSy - ASy;
            double dx = vTx - vAx, dy = vTy - vAy;
            double a = dx*dx + dy*dy;
            double b = 2*(d0x*dx + d0y*dy);
            double c = d0x*d0x + d0y*d0y;
            best = min(best, min_on_interval(a,b,c, 0.0L, minT));
        }

        // 2) one stopped, one moving: t in [minT, maxT]
        if(Tt < Ta){
            // Takahashi stopped at TG (constant), Aoki still moving
            // difference = (TG) - (AS + vA * t) = (TG - AS) + (-vA)*t
            double d0x = TGx - ASx, d0y = TGy - ASy;
            double dx = -vAx, dy = -vAy;
            double a = dx*dx + dy*dy;
            double b = 2*(d0x*dx + d0y*dy);
            double c = d0x*d0x + d0y*d0y;
            best = min(best, min_on_interval(a,b,c, Tt, Ta));
        } else if(Ta < Tt){
            // Aoki stopped at AG, Takahashi still moving
            // difference = (TS + vT * t) - AG = (TS - AG) + vT * t
            double d0x = TSx - AGx, d0y = TSy - AGy;
            double dx = vTx, dy = vTy;
            double a = dx*dx + dy*dy;
            double b = 2*(d0x*dx + d0y*dy);
            double c = d0x*d0x + d0y*d0y;
            best = min(best, min_on_interval(a,b,c, Ta, Tt));
        }
        // 3) after both stopped (t >= maxT) distance constant: evaluate at t = maxT (already included endpoints above,
        // but to be safe evaluate final positions)
        {
            double fx = TGx - AGx, fy = TGy - AGy;
            double val = fx*fx + fy*fy;
            best = min(best, val);
        }

        cout << sqrt((double)best) << "\n";
    }

    return 0;
}
