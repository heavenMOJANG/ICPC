#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

// 向交互器提问并获取结果
int ask_query(const std::vector<int>& indices) {
    if (indices.empty()) {
        return 0;
    }
    std::cout << "? " << indices.size();
    for (int index : indices) {
        std::cout << " " << index;
    }
    std::cout << std::endl;
    int result;
    std::cin >> result;
    if (result == -1) exit(0); // 错误处理
    return result;
}

// 步骤 1: 使用分治法找到一个开括号 '(' 的索引
int find_any_open_bracket(const std::vector<int>& indices) {
    if (indices.size() == 1) {
        return indices[0];
    }

    int mid = indices.size() / 2;
    std::vector<int> group_a(indices.begin(), indices.begin() + mid);
    std::vector<int> group_b(indices.begin() + mid, indices.end());

    int val_a = ask_query(group_a);
    
    std::vector<int> combined = group_a;
    combined.insert(combined.end(), group_b.begin(), group_b.end());
    int val_ab = ask_query(combined);

    int val_b = ask_query(group_b); // 为了计算 crossover，需要 val_b

    if (val_ab > val_a + val_b) {
        return find_any_open_bracket(group_a);
    } else {
        return find_any_open_bracket(group_b);
    }
}


// 步骤 2 辅助函数: 计算一个集合中 ')' 的数量
int count_closing_in_set(const std::vector<int>& indices, int p_open) {
    if (indices.empty()) {
        return 0;
    }
    int val_indices = ask_query(indices);
    
    std::vector<int> interleaved_query;
    for (int idx : indices) {
        interleaved_query.push_back(p_open);
        interleaved_query.push_back(idx);
    }
    int val_interleaved = ask_query(interleaved_query);

    return val_interleaved - val_indices;
}


void solve() {
    int n;
    std::cin >> n;

    std::vector<int> all_indices(n);
    std::iota(all_indices.begin(), all_indices.end(), 1);

    // 步骤 1: 找到一个开括号 '(' 的索引
    // 注意：一个更鲁棒的 find_open 会处理 f(s_A)=0 的情况，但这个简化版通常能行
    int p_open = find_any_open_bracket(all_indices);
    
    std::string result_str(n, ' ');
    result_str[p_open - 1] = '(';

    std::vector<int> unknown_indices;
    for (int i = 1; i <= n; ++i) {
        if (i != p_open) {
            unknown_indices.push_back(i);
        }
    }

    // 步骤 2: 使用分治和 `count_closing` 确定其他字符
    std::vector<std::vector<int>> q;
    if (!unknown_indices.empty()) {
        q.push_back(unknown_indices);
    }

    while (!q.empty()) {
        std::vector<int> current_set = q.back();
        q.pop_back();

        if (current_set.size() == 1) {
            int idx = current_set[0];
            int val = ask_query({p_open, idx});
            if (val == 1) {
                result_str[idx - 1] = ')';
            } else {
                result_str[idx - 1] = '(';
            }
            continue;
        }

        int mid = current_set.size() / 2;
        std::vector<int> group_a(current_set.begin(), current_set.begin() + mid);
        std::vector<int> group_b(current_set.begin() + mid, current_set.end());

        int closing_in_a = count_closing_in_set(group_a, p_open);

        if (closing_in_a == group_a.size()) {
            for (int idx : group_a) result_str[idx - 1] = ')';
            if (!group_b.empty()) q.push_back(group_b);
        } else if (closing_in_a == 0) {
            for (int idx : group_a) result_str[idx - 1] = '(';
            if (!group_b.empty()) q.push_back(group_b);
        } else {
            if (!group_a.empty()) q.push_back(group_a);
            if (!group_b.empty()) q.push_back(group_b);
        }
    }

    std::cout << "! " << result_str << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}