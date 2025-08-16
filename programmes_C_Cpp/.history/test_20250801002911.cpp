#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 发送一次查询，读取交互返回值
ll ask(const vector<int>& idx) {
    cout << "? " << idx.size();
    for (int x : idx) cout << " " << x;
    cout << "\n" << flush;
    ll res;
    cin >> res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        // ——1. 二分找 ) 枢轴 j——
        int lo = 2, hi = n, pivot_close = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<int> qry(mid);
            iota(qry.begin(), qry.end(), 1);
            if (ask(qry) > 0) {
                pivot_close = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // ——2. 二分找 ( 枢轴 i——
        int l = 1, r = pivot_close - 1, pivot_open = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ask({mid, pivot_close}) > 0) {
                pivot_open = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // 准备分组
        int B = 100;  // 组数
        vector<string> ans(T>0?1:0); // dummy
        vector<char> s(n+1, '?');

        // 我们已经知道 i 是 '('，j 是 ')'
        s[pivot_open] = '(';
        s[pivot_close] = ')';

        // 将其余位置分到 B 组
        vector<vector<int>> group(B);
        for (int x = 1; x <= n; x++) {
            if (x==pivot_open || x==pivot_close) continue;
            group[x % B].push_back(x);
        }

        // 分组计数
        for (auto &g : group) {
            int k = g.size();
            if (k == 0) continue;
            // 造一次长度 2k 的查询：g + k 个 pivot_close
            vector<int> qry;
            qry.reserve(2*k);
            for (int x : g) qry.push_back(x);
            for (int i = 0; i < k; i++) qry.push_back(pivot_close);

            ll cnt_open = ask(qry);  // 这一组里 '(' 的总数
            if (cnt_open == 0) {
                // 全是 ')'
                for (int x : g) s[x] = ')';
            } else if (cnt_open == k) {
                // 全是 '('
                for (int x : g) s[x] = '(';
            } else {
                // 杂组：逐点询问
                for (int x : g) {
                    // ask({x, pivot_close})==1 <=> s[x]=='('
                    s[x] = (ask({x, pivot_close}) == 1 ? '(' : ')');
                }
            }
        }

        // 输出答案
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << s[i];
        cout << "\n" << flush;
    }

    return 0;
}
