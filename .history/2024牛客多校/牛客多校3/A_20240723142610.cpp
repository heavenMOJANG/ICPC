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
    for (int i = 0; i < n; ++ i) {
        cin >> h[i];
        if (h[i] & 1 == 0) h[i] --;
    }
    n -= L;
    int k = n / (R - L);
    int r = n % (R - L);
    if (!r) {
        int to = k + 1, back = k;
    } else {
        int 
    }
    return 0;
}