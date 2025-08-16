#include <bits/stdc++.h>
using namespace std;

// セグメント木ノードの定義
struct Node {
    int ans;    // 区間内の最大連続長
    int len;    // 区間の長さ
    char lv;    // 区間の左端文字
    char rv;    // 区間の右端文字
    int lcnt;   // 左端からの連続長
    int rcnt;   // 右端からの連続長

    Node() : ans(0), len(0), lv(0), rv(0), lcnt(0), rcnt(0) {}
    Node(char ch) : ans(1), len(1), lv(ch), rv(ch), lcnt(1), rcnt(1) {}
};

// ノードをマージする関数
Node merge(const Node& left, const Node& right) {
    if (left.len == 0) return right;
    if (right.len == 0) return left;

    Node res;
    res.len = left.len + right.len;
    res.lv = left.lv;
    res.rv = right.rv;

    // 左からの連続長
    if (left.lcnt == left.len && left.lv == right.lv)
        res.lcnt = left.len + right.lcnt;
    else
        res.lcnt = left.lcnt;

    // 右からの連続長
    if (right.rcnt == right.len && left.rv == right.lv)
        res.rcnt = right.len + left.rcnt;
    else
        res.rcnt = right.rcnt;

    // 最大連続長
    res.ans = max(left.ans, right.ans);
    if (left.rv == right.lv)
        res.ans = max(res.ans, left.rcnt + right.lcnt);

    return res;
}

// グローバル変数
int N, Q;
string S;
vector<Node> seg;

// セグメント木の構築
void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = Node(S[l - 1]);
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
}

// 点更新
void update(int node, int l, int r, int idx, char ch) {
    if (l == r) {
        seg[node] = Node(ch);
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, ch);
    else
        update(node * 2 + 1, mid + 1, r, idx, ch);
    seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
}

// 区間クエリ
Node query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return Node(); // 空ノード
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    Node left = query(node * 2, l, mid, ql, qr);
    Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
    return merge(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    cin >> S;
    seg.resize(4 * N); // セグメント木のサイズ確保

    build(1, 1, N); // 1-indexed

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos;
            char ch;
            cin >> pos >> ch;
            update(1, 1, N, pos, ch);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, N, l, r);
            cout << res.ans << '\n';
        }
    }

    return 0;
}
