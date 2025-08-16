#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

// 全局变量以便于在递归函数中访问
std::string result_str;
int p_open;

// 辅助函数：向交互器提问并获取结果
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
    if (result == -1) exit(0);
    return result;
}

// 递归函数，用于识别一批未知索引的字符类型
void classify_indices(std::vector<int> indices) {
    if (indices.empty()) {
        return;
    }

    // 关键操作：用 2 次查询计算这批索引中有多少个 ')'
    int val_indices_only = ask_query(indices);
    std::vector<int> interleaved_query;
    for (int idx : indices) {
        interleaved_query.push_back(p_open);
        interleaved_query.push_back(idx);
    }
    int val_interleaved = ask_query(interleaved_query);
    int num_closing = val_interleaved - val_indices_only;

    // 根据 ')' 的数量做出判断
    if (num_closing == 0) { // 如果没有 ')'，则全部是 '('
        for (int idx : indices) result_str[idx - 1] = '(';
    } else if (num_closing == indices.size()) { // 如果全是 ')'
        for (int idx : indices) result_str[idx - 1] = ')';
    } else { // 如果是混合的，则一分为二，继续递归
        int mid = indices.size() / 2;
        std::vector<int> group_a(indices.begin(), indices.begin() + mid);
        std::vector<int> group_b(indices.begin() + mid, indices.end());
        classify_indices(group_a);
        classify_indices(group_b);
    }
}

void solve() {
    int n;
    std::cin >> n;
    result_str.assign(n, ' ');

    // 步骤 1: 找到第一个 ')' 的位置 (p_close)
    int low = 1, high = n, p_close = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        std::vector<int> prefix_indices;
        for (int i = 1; i <= mid; ++i) prefix_indices.push_back(i);
        
        if (ask_query(prefix_indices) > 0) {
            p_close = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    result_str[p_close - 1] = ')';

    // 步骤 2: 找到与 p_close 配对的 '(' (p_open)
    low = 1, high = p_close - 1, p_open = -1;
    while(low <= high) {
        int mid = low + (high-low) / 2;
        std::vector<int> range_indices;
        for(int i = mid; i <= p_close; ++i) range_indices.push_back(i);

        if (ask_query(range_indices) == 1) {
            p_open = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    result_str[p_open - 1] = '(';
    
    // 步骤 3: 识别所有剩下的字符
    std::vector<int> unknown_indices;
    for (int i = 1; i <= n; ++i) {
        if (i != p_open && i != p_close) {
            unknown_indices.push_back(i);
        }
    }
    classify_indices(unknown_indices);

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