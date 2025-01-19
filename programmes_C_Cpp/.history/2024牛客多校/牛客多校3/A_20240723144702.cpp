#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 5e5 + 10;
int n, L, R, h[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> L >> R;
    if (n <= R) {cout << "YES\n"; return 0;}
    map<int,int> mp;
    int cntTo = 0, cntBack = 0;
    for (int i = 0; i < n; ++ i) {
        cin >> h[i];
        if (h[i] & 1 == 0) h[i] --;
        cntTo += h[i] - h[i] / 2;
        cntBack += h[i] / 2;
    }
    n -= L;
    int k = n / (R - L);
    int r = n % (R - L);
    int to, back;
    if (!r) {
        to = k * R, back = (k - 1) * L;
    } else {
        to = k * R + r + L, back = k * L;
    }
    cout << (cntTo >= to && cntBack >= back? "YES\n" : "NO\n");
    return 0;
}