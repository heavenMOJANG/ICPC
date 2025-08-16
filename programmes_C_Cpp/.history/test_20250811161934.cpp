#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
void read(__int128 & n) {
    __int128 x = 0,f = 1;
    char ch =  getchar();
    while (ch <'0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar();}
    n = x * f;
}
void write(__int128 n) {
    if (n < 0) {putchar('-'); n *= -1;}
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

}
int main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; read(_);
    // 计算每个寿命 r=1.. 的人数 counts[r-1]
    vector<i128> counts; // counts[0] 对应寿命 1
    i128 N = n;
    long long round = 1;
    while (true) {
        if (N < w) {
            // 这一轮开始但人数不足 w：这些人活到当前轮数 (round)
            if (N > 0) counts.push_back(N);
            break;
        } else {
            i128 e = N / w;      // 本轮被淘汰人数，寿命 = round
            counts.push_back(e);
            N = N - e;           // 幸存者进入下一轮
            ++round;
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

    cout << to_string_i128(ans) << "\n";
    return 0;
}
