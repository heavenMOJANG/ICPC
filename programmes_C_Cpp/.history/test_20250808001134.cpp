#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

// 使用结构体来表示区间，使代码更清晰
struct Interval {
    long long start;
    long long end;
};

// 用于排序区间的比较函数
bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n), b(n);
    std::vector<Interval> intervals(n);
    long long initial_score = 0;

    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];

    // 步骤 1: 计算初始分数并创建区间
    for (int i = 0; i < n; ++i) {
        initial_score += std::abs(a[i] - b[i]);
        intervals[i] = {std::min(a[i], b[i]), std::max(a[i], b[i])};
    }

    // 步骤 2: 合并重叠区间以找到连通分量
    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    std::vector<Interval> merged_intervals;
    if (n > 0) {
        merged_intervals.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            Interval& last_merged = merged_intervals.back();
            const Interval& current = intervals[i];
            
            // 如果当前区间与最后一个合并后的区间重叠或接触
            if (current.start <= last_merged.end) {
                // 合并它们，更新末端点
                last_merged.end = std::max(last_merged.end, current.end);
            } else {
                // 如果不重叠，则开始一个新的连通分量
                merged_intervals.push_back(current);
            }
        }
    }

    // 步骤 3 & 4: 计算免费回合和有代价回合
    int m = merged_intervals.size();
    long long free_rounds = n - m; // 从 n 个区间合并到 m 个连通分量需要 n-m 次免费合并
    long long costly_rounds = k - free_rounds;

    long long additional_cost = 0;

    // 步骤 5: 如果需要，计算有代价回合的最小成本
    if (costly_rounds > 0) {
        // 计算所有连通分量之间的间隙
        std::vector<long long> gaps;
        for (size_t i = 0; i < merged_intervals.size() - 1; ++i) {
            long long gap = merged_intervals[i+1].start - merged_intervals[i].end;
            if (gap > 0) {
                gaps.push_back(gap);
            }
        }
        
        std::sort(gaps.begin(), gaps.end());
        
        long long sum_of_smallest_gaps = 0;
        // 选取 'costly_rounds' 个最小的间隙
        for (long long i = 0; i < std::min((long long)gaps.size(), costly_rounds); ++i) {
            sum_of_smallest_gaps += gaps[i];
        }
        
        additional_cost = 2 * sum_of_smallest_gaps;
    }

    // 步骤 6: 计算最终得分
    long long final_score = initial_score + additional_cost;
    std::cout << final_score << std::endl;
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