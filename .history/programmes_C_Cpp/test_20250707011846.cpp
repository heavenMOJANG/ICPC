#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;

// Fenwick tree structure is fine.
struct fenwick {
    int n;
    vector<int> t;
    fenwick(int _) : n(_), t(_ + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    void update(int x, int d) { while (x <= n) t[x] += d, x += lowbit(x); }
    int query(int x) {
        if (x < 1) return 0; // Guard for querying value 0 or less
        int res{};
        while (x) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1); // Stores compressed values
    vector<int> b(n + 1); // Stores original values for tie-breaking

    // --- Fix 1: Coordinate Compression ---
    map<int, int> val_to_compressed;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        val_to_compressed[b[i]] = 0; // Collect all unique values
    }
    int compressed_id_counter = 0;
    for (auto& pair : val_to_compressed) {
        pair.second = ++compressed_id_counter;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = val_to_compressed[b[i]];
    }
    int max_compressed_val = compressed_id_counter;
    // --- End Fix 1 ---

    if (k == 1) { cout << "YES\n"; return; }
    
    fenwick ft(max_compressed_val);
    vector<int> cnt(max_compressed_val + 1, 0);
    for (int i = 1; i <= n; ++ i) ft.update(a[i], 1), cnt[a[i]] ++;
    
    vector<int> prev(n + 2), next(n + 2);
    for (int i = 0; i <= n + 1; ++ i) prev[i] = i - 1, next[i] = i + 1;
    
    int l = 1, r = n;
    
    while (l < r) {
        // We can only operate if the current array size is at least k
        if (ft.query(max_compressed_val) < k) {
            break;
        }

        if (a[l] == a[r]) {
            l = next[l];
            r = prev[r];
            continue;
        }
        
        auto check = [&](int p) {
            int val = a[p];
            int sum0 = ft.query(val - 1); // count of elements < a[p]
            int sum1 = cnt[val];           // count of elements == a[p]
            return sum0 < k && k <= sum0 + sum1;
        };
        
        // --- Fix 2: Improved Greedy Choice ---
        bool can_l = check(l);
        bool can_r = check(r);
        
        int p_to_remove = -1;
        if (can_l && can_r) {
            // Both are removable, choose the one with the larger original value
            p_to_remove = (b[l] > b[r]) ? l : r;
        } else if (can_l) {
            p_to_remove = l;
        } else if (can_r) {
            p_to_remove = r;
        }
        
        if (p_to_remove != -1) {
            ft.update(a[p_to_remove], -1);
            cnt[a[p_to_remove]]--;
            
            // Update pointers based on which element was removed
            if (p_to_remove == l) {
                l = next[l];
            } else { // p_to_remove == r
                r = prev[r];
            }
            // "Delete" the element from the linked list
            int pr_node = prev[p_to_remove];
            int nx_node = next[p_to_remove];
            next[pr_node] = nx_node;
            prev[nx_node] = pr_node;

        } else {
            // Neither endpoint is removable, we are stuck with this strategy
            cout << "NO\n";
            return;
        }
        // --- End Fix 2 ---
    }
    
    // If the loop finishes, it means we successfully reduced the array
    // until the pointers crossed or met.
    cout << "YES\n";
    return;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}