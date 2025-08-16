#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
void read(__int128 & n) {
    __int128 x = 0,f = 1;
    char ch =  getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    n = x * f;
}
void write(__int128 n) {
    if (n < 0) { putchar('-'); n *= -1; }
    static __int128 sta[256];
    __int128 top=0;
    do {
        sta[top ++] = n % 10, n /= 10;
    } while(n);
    while(top) putchar(sta[-- top] + 48);
}
void solve() {
    i128 n, w; read(n); read(w);
    if (w == 1) { write(n * (n + 1) / 2); puts(""); return; }
    vector<i128> counts;
    i128 N = n, ctr = 1;
    while (true) {
        if (N < w) {
            if (N > 0) counts.emplace_back(N);
            break;
        } else {
            i128 d = N / w;
            counts.emplace_back(d);
            N -= d;
            ctr ++;
        }
    }

    // 按寿命从大到小分配最大值
    i128 cur = n; // 下一个分配的最大值
    i128 ans = 0;
    for (int idx = (int)counts.size() - 1; idx >= 0; --idx) {
        i128 k = counts[idx];
        if (k == 0) continue;
        // 等差和 cur + (cur-1) + ... (k 项)
        i128 sumvals = k * ( (i128)2 * cur - k + 1 ) / 2;
        i128 lifetime = (i128)(idx + 1);
        ans += lifetime * sumvals;
        cur -= k;
    }
    write(ans); puts("");
}
int main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    i128 _ = 1; read(_);
    while (_ --) solve();
    

    cout << to_string_i128(ans) << "\n";
    return 0;
}
