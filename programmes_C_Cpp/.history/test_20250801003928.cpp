#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n+1), r(n+1,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int,int>> seg(n);
        int maxCoord = 0;
        for (int i = 0; i < n; i++) {
            cin >> seg[i].first >> seg[i].second;
            maxCoord = max(maxCoord, seg[i].second);
        }

        // 为每个区间记录 (length, index)
        vector<pair<int,int>> ord;
        ord.reserve(n);
        for (int i = 0; i < n; i++) {
            int len = seg[i].second - seg[i].first;
            ord.emplace_back(len, i);
        }
        // 按长度从大到小排序
        sort(ord.begin(), ord.end(),
             [](auto &a, auto &b){
                 return a.first > b.first;
             });

        DSU dsu(maxCoord);
        vector<int> answer;
        answer.reserve(n);

        // 贪心选边，无环则加入
        for (auto &pr : ord) {
            int idx = pr.second;
            int u = seg[idx].first;
            int v = seg[idx].second;
            if (dsu.unite(u, v)) {
                answer.push_back(idx + 1);  // 1-based 输出
            }
        }

        // 输出
        cout << answer.size() << "\n";
        for (int i = 0; i < (int)answer.size(); i++) {
            cout << answer[i] << (i+1<answer.size() ? ' ' : '\n');
        }
    }
    return 0;
}
