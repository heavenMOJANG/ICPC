#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fenw {
    vector<int> tree;
    int n;
    Fenw(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    void update(int index, int delta) {
        for (int i = index + 1; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }
    int prefix_sum(int index) {
        if (index < 0) return 0;
        int s = 0;
        for (int i = index + 1; i > 0; i -= i & -i) {
            s += tree[i];
        }
        return s;
    }
    int range_sum(int l, int r) {
        if (l > r) return 0;
        int sum_r = prefix_sum(r);
        int sum_l_minus = (l > 0) ? prefix_sum(l - 1) : 0;
        return sum_r - sum_l_minus;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (k == 1) {
            cout << "YES\n";
            continue;
        }

        bool is_palindrome = true;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] != a[n - 1 - i]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            cout << "YES\n";
            continue;
        }

        vector<int> first(n + 1, -1);
        vector<int> last(n + 1, -1);
        vector<vector<int>> positions(n + 1);

        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (first[x] == -1) first[x] = i;
            last[x] = i;
            positions[x].push_back(i);
        }

        Fenw fenw(n);
        bool found = false;
        for (int x = 1; x <= n; x++) {
            if (first[x] == -1) continue;
            if (last[x] - first[x] >= k - 1) {
                int L = first[x];
                int R = last[x];
                int count1 = fenw.range_sum(L, R);
                int freq = positions[x].size();
                int count2 = count1 + freq;
                if (count1 < k && count2 >= k) {
                    found = true;
                    break;
                }
            }
            for (int pos : positions[x]) {
                fenw.update(pos, 1);
            }
        }

        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}