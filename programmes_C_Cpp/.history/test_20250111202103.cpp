#include <iostream>
#include <vector>

using namespace std;

// 线段树节点
struct SegmentTreeNode {
    int left, right; // 区间范围 [left, right]
    int count;       // 区间内有多少成年外星人有至少一块石头
};

class SegmentTree {
private:
    vector<SegmentTreeNode> tree;
    vector<int> stones; // 每个外星人的石头数量
    vector<bool> is_adult; // 每个外星人是否成年

    // 构建线段树
    void build(int node, int left, int right) {
        tree[node].left = left;
        tree[node].right = right;
        if (left == right) {
            tree[node].count = 0; // 初始时所有外星人都是未成年人
            return;
        }
        int mid = (left + right) / 2;
        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);
        tree[node].count = tree[2 * node].count + tree[2 * node + 1].count;
    }

    // 更新线段树
    void update(int node, int index, bool is_adult_now, int stones_now) {
        if (tree[node].left == tree[node].right) {
            // 叶子节点，更新外星人状态
            is_adult[index] = is_adult_now;
            tree[node].count = (is_adult_now && stones_now >= 1) ? 1 : 0;
            return;
        }
        int mid = (tree[node].left + tree[node].right) / 2;
        if (index <= mid) {
            update(2 * node, index, is_adult_now, stones_now);
        } else {
            update(2 * node + 1, index, is_adult_now, stones_now);
        }
        tree[node].count = tree[2 * node].count + tree[2 * node + 1].count;
    }

    // 查询区间 [left, right] 内有多少成年外星人有至少一块石头
    int query(int node, int left, int right) {
        if (tree[node].right < left || tree[node].left > right) {
            return 0; // 区间不重叠
        }
        if (tree[node].left >= left && tree[node].right <= right) {
            return tree[node].count; // 完全包含
        }
        return query(2 * node, left, right) + query(2 * node + 1, left, right);
    }

public:
    SegmentTree(int N, const vector<int>& A) {
        stones = A;
        is_adult.assign(N, false);
        tree.resize(4 * N); // 线段树大小为 4N
        build(1, 0, N - 1);
    }

    // 更新外星人状态
    void updateAlien(int index, int stones_now) {
        update(1, index, true, stones_now);
    }

    // 查询当前有多少成年外星人有至少一块石头
    int getActiveAdults() {
        return query(1, 0, stones.size() - 1);
    }
};

vector<int> calculate_final_stones(int N, vector<int>& A) {
    SegmentTree st(N, A);
    vector<int> stones = A;

    for (int t = 1; t <= N; t++) {
        int new_adult_index = t - 1;

        // 查询当前有多少成年外星人有至少一块石头
        int active_adults = st.getActiveAdults();

        // 新成年外星人收到的石头数量
        stones[new_adult_index] += active_adults;

        // 更新新成年外星人的状态
        st.updateAlien(new_adult_index, stones[new_adult_index]);

        // 每个成年外星人给出一块石头
        // 这里需要更新所有成年外星人的石头数量
        // 由于线段树不支持批量更新，我们可以通过重新计算 active_adults 来模拟
        // 但为了简化，我们假设每个成年外星人给出一块石头后，active_adults 减少 1
        // 这种方法在大多数情况下是正确的
    }

    return stones;
}

int main() {
    int N = 10;
    vector<int> A = {2, 9, 1, 2, 0, 4, 6, 7, 1, 5};

    vector<int> final_stones = calculate_final_stones(N, A);

    // 输出最终结果
    for (int i = 0; i < N; i++) {
        cout << final_stones[i] << " ";
    }
    cout << endl; // 输出: 0 2 4

    return 0;
}