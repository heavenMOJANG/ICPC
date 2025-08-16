#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int l = 0, r = n - 1;
        deque<int> tail;  // 保存 q 的最后最多 4 个元素
        string ans;
        ans.reserve(n);

        auto safe_push = [&](int x) {
            // 如果 tail.size() < 4，一定安全（不足 5 个元素）
            if (tail.size() < 4) return true;
            // 否则取出 tail 的最后 4 个，加上 x，看是否五连增或五连减
            int a = tail[tail.size() - 4];
            int b = tail[tail.size() - 3];
            int c = tail[tail.size() - 2];
            int d = tail[tail.size() - 1];
            int e = x;
            // 检查严格递增
            if (a < b && b < c && c < d && d < e) return false;
            // 检查严格递减
            if (a > b && b > c && c > d && d > e) return false;
            return true;
        };

        for (int step = 0; step < n; step++){
            int xl = p[l], xr = p[r];
            bool okL = safe_push(xl);
            bool okR = safe_push(xr);

            if (okL && (!okR || true)) {
                // 优先取 L（若两者都安全，也可取 L）
                ans.push_back('L');
                // 更新 tail
                if (tail.size() == 4) tail.pop_front();
                tail.push_back(xl);
                l++;
            } else {
                // 否则取 R
                ans.push_back('R');
                if (tail.size() == 4) tail.pop_front();
                tail.push_back(xr);
                r--;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
