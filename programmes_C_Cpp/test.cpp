#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <print>
#include <atcoder/segtree>

using namespace std;
using namespace atcoder;

constexpr long long INF = 1e18;

// 线段树节点状态
struct S {
    long long sum;
    long long ans;
};

// C++20 起支持的指示器初始化，语义极度清晰
S op(S a, S b) {
    return S{.sum = a.sum + b.sum, .ans = max(b.ans, a.ans + b.sum)};
}

S e() {
    return S{.sum = 0LL, .ans = -INF};
}

int main() {
    // 解绑 I/O
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> a(n + 1), b(n + 1);
    
    // 现代 C++ 循环：用 views::iota 代替传统的 for(int i=1; i<=n; ++i)
    for (int i : views::iota(1, n + 1)) cin >> a[i];
    for (int i : views::iota(1, n + 1)) cin >> b[i];

    struct Query {
        int type, i;
        long long x;
    };
    
    vector<Query> queries(q);
    vector<long long> vals;
    vals.reserve(n + q); // 预分配内存，降低动态扩容的常数开销

    for (int i : views::iota(1, n + 1)) vals.push_back(b[i]);
    
    // 结构化绑定直接读取 queries
    for (auto& [type, idx, x] : queries) {
        cin >> type >> idx >> x;
        if (type == 2) vals.push_back(x);
    }

    // --------------------------------------------------------
    // C++ 26 风格的离散化：完全舍弃 .begin() 和 .end()
    ranges::sort(vals);
    // ranges::unique 返回的是将被擦除的垃圾数据区间 [first, last)
    auto [first_to_erase, last_to_erase] = ranges::unique(vals);
    vals.erase(first_to_erase, last_to_erase);

    auto get_id = [&](long long val) {
        // ranges::lower_bound 直接传入容器
        return ranges::lower_bound(vals, val) - vals.begin();
    };
    // --------------------------------------------------------

    int m = vals.size();
    vector<long long> sum_a(m, 0);
    
    for (int i : views::iota(1, n + 1)) {
        sum_a[get_id(b[i])] += a[i];
    }

    vector<S> init_v(m);
    
    // C++ 23/26 的 enumerate：同时遍历索引和值，极其优雅
    for (auto [i, sum] : views::enumerate(sum_a)) {
        if (sum > 0) {
            init_v[i] = S{.sum = sum, .ans = sum + vals[i]};
        } else {
            init_v[i] = e();
        }
    }

    segtree<S, op, e> seg(init_v);

    auto update_bucket = [&](int id) {
        if (sum_a[id] > 0) {
            seg.set(id, S{.sum = sum_a[id], .ans = sum_a[id] + vals[id]});
        } else {
            seg.set(id, e());
        }
    };

    // 核心处理逻辑：利用 const auto& 结构化绑定解包
    for (const auto& [type, idx, x] : queries) {
        if (type == 1) {
            int b_id = get_id(b[idx]);
            // 采用 += 增量更新，少做一次减法
            sum_a[b_id] += x - a[idx];
            a[idx] = x;
            update_bucket(b_id);
        } else {
            int old_b = get_id(b[idx]);
            sum_a[old_b] -= a[idx];
            update_bucket(old_b);

            b[idx] = x;
            
            int new_b = get_id(x);
            sum_a[new_b] += a[idx];
            update_bucket(new_b);
        }
        
        // C++ 23/26 极速标准输出，无需 cout 和 '\n'
        println("{}", seg.all_prod().ans);
    }

    return 0;
}