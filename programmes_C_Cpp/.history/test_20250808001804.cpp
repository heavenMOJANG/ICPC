#include <iostream>
#include <vector>
#include <numeric>      // 为了使用 std::accumulate
#include <algorithm>
#include <cmath>

// 主解决函数
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    
    std::vector<long long> a(n), b(n);
    long long initial_score = 0;
    // 使用 std::pair 代替 struct 来表示区间
    std::vector<std::pair<long long, long long>> intervals(n);

    // 1. 计算初始分数并创建区间
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        initial_score += std::abs(a[i] - b[i]);
        intervals[i] = {std::min(a[i], b[i]), std::max(a[i], b[i])};
    }

    // 2. 排序并合并区间，找到连通分量
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::pair<long long, long long>> components;
    if (n > 0) {
        components.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            // 如果当前区间与最后一个连通分量重叠
            if (intervals[i].first <= components.back().second) {
                // 合并：扩展连通分量的右边界
                components.back().second = std::max(components.back().second, intervals[i].second);
            } else {
                // 否则，它是一个新的连通分量
                components.push_back(intervals[i]);
            }
        }
    }

    int m = components.size();
    
    // k 次合并后，最终应该剩下 n - k 个组。
    // 我们现在有 m 个连通分量。
    // 如果 m > n - k，我们还需要进行 m - (n - k) 次有代价的合并。
    long long costly_merges_needed = std::max(0LL, (long long)m - (n - k));

    long long additional_cost = 0;
    if (costly_merges_needed > 0 && m > 1) {
        // 3. 计算连通分量之间的间隙
        std::vector<long long> gaps;
        for (int i = 0; i < m - 1; ++i) {
            gaps.push_back(components[i+1].first - components[i].second);
        }
        std::sort(gaps.begin(), gaps.end());
        
        // 4. 使用 accumulate 计算最小的几个间隙的总和
        // 代价是这些最小间隙总和的两倍
        additional_cost = 2 * std::accumulate(gaps.begin(), gaps.begin() + costly_merges_needed, 0LL);
    }
    
    // 5. 最终得分 = 初始得分 + 额外代价
    std::cout << initial_score + additional_cost << std::endl;
}

int main() {
    // 优化 C++ 的 I/O 速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}