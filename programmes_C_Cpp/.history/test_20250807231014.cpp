#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// 使用 long long 避免溢出
using ll = long long;

void solve() {
    int n;
    ll k;
    std::cin >> n >> k;
    std::vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];

    ll total_diff = 0;
    std::vector<std::pair<ll, ll>> segs(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) std::swap(a[i], b[i]);
        segs[i] = {a[i], b[i]};
        total_diff += b[i] - a[i];
    }

    // 按左端点排序区间
    std::sort(segs.begin(), segs.end());

    // 合并重叠区间，并记录组件间的间隙
    std::vector<ll> gaps;
    // 当前合并后组件的最右端点
    ll current_max_r = segs[0].second;
    int num_comps = 1;

    for (int i = 1; i < n; ++i) {
        // 如果新区间在当前组件之外，说明是一个新组件
        if (segs[i].first > current_max_r) {
            // 记录两个组件之间的间隙
            gaps.push_back(segs[i].first - current_max_r);
            num_comps++;
        }
        // 将当前区间合并到组件中，更新最右端点
        current_max_r = std::max(current_max_r, segs[i].second);
    }
    
    // 零成本操作的次数 = 总区间数 - 组件数
    ll zero_gain_moves = n - num_comps;
    ll gain = 0;

    // 如果 k 大于零成本操作次数，就必须进行有成本的操作
    if (k > zero_gain_moves) {
        ll costly_moves = k - zero_gain_moves;
        std::sort(gaps.begin(), gaps.end());
        
        // 贪心选择最小的间隙进行合并
        for (size_t i = 0; i < std::min((size_t)costly_moves, gaps.size()); ++i) {
            gain += gaps[i] * 2;
        }
    }

    std::cout << total_diff + gain << "\n";
}

int main() {
    // 快速 IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}