#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

string to_string_i128(i128 x){
    if (x == 0) return "0";
    bool neg = x < 0;
    if (neg) x = -x;
    string s;
    while (x > 0){
        int d = (int)(x % 10);
        s.push_back('0' + d);
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n_ll;
    long long w_ll;
    // 读一组 (如果需要多组改成先读T)
    if (!(cin >> n_ll >> w_ll)) return 0;
    i128 n = (i128)n_ll;
    long long w = w_ll;

    // 边界（题中已给 1 < w < n）
    if (n_ll <= 0) { cout << 0 << "\n"; return 0; }

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
