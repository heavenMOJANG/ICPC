#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;
void read(i128& n) {
    __int128 x{}, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    n = x * f;
}
void write(i128 n) {
    if (n < 0) { putchar('-'); n *= -1; }
    static __int128 sta[256];
    __int128 top{};
    do {
        sta[top ++] = n % 10, n /= 10;
    } while(n);
    while(top) putchar(sta[-- top] + 48);
}
void solve() {
    i128 n, w; read(n); read(w);
    if (w == 1) { write(n * (n + 1) / 2); puts(""); return; }
    vector<int> rd;
    int N = n, cnt = 1;
    for (;;)
        if (N < w) {
            if (N) rd.emplace_back(N);
            break;
        } else {
            int d = N / w;
            rd.emplace_back(d);
            N -= d;
            cnt ++;
        }
    i128 cur = n, ans{};
    for (int i = rd.size() - 1; ~i; -- i) {
        i128 k = rd[i];
        if (k == 0) continue;
        i128 s = k * (cur * 2 - k + 1) / 2;
        i128 t = i + 1;
        ans += t * s;
        cur -= k;
    }
    write(ans); puts("");
}
int main(){
    i128 _ = 1; read(_);
    while(_ --) solve();
    return 0;
}