#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;

struct fenwick {
    int n;
    vector<int> t;
    fenwick(int _) : n(_), t(_ + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    void update(int x, int d) {
        if (x < 1) return;
        while (x <= n) t[x] += d, x += lowbit(x);
    }
    int query(int x) {
        if (x < 1) return 0;
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
    vector<int> a(n + 1); // Will store compressed values

    // --- Fix 1: Coordinate Compression (Essential) ---
    map<int, int> val_to_compressed;
    for (int i = 1; i <= n; ++i) {
        int original_val;
        cin >> original_val;
        a[i] = original_val; // Temporarily store original value
        val_to_compressed[original_val] = 0;
    }
    int compressed_id_counter = 0;
    for (auto& pair : val_to_compressed) {
        pair.second = ++compressed_id_counter;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = val_to_compressed[a[i]];
    }
    int max_compressed_val = compressed_id_counter;
    // --- End Fix 1 ---

    if (k == 1) { cout << "YES\n"; return; }
    
    fenwick ft(max_compressed_val);
    vector<int> cnt(max_compressed_val + 1, 0);
    for (int i = 1; i <= n; ++ i) ft.update(a[i], 1), cnt[a[i]]++;
    
    vector<int> prev(n + 2), next(n + 2);
    for (int i{}; i <= n + 1; ++ i) prev[i] = i - 1, next[i] = i + 1;
    
    // --- Fix 2: Replace Flawed Two-Pointer Logic with Iterative Peeling ---
    while (true) {
        if (ft.query(max_compressed_val) < k) break; // Stop if array too small

        int val_to_remove = -1;
        // Find the LARGEST removable value
        for (int v = max_compressed_val; v >= 1; --v) {
            if (cnt[v] == 0) continue;
            int sum_less = ft.query(v - 1);
            int sum_le = sum_less + cnt[v];
            if (sum_less < k && k <= sum_le) {
                val_to_remove = v;
                break;
            }
        }
        
        if (val_to_remove == -1) break; // No more elements are removable

        // Collect all indices of the value to remove
        vector<int> indices_to_delete;
        int current_idx = next[0];
        while (current_idx <= n) {
            if (a[current_idx] == val_to_remove) {
                indices_to_delete.push_back(current_idx);
            }
            current_idx = next[current_idx];
        }

        // Batch update data structures
        ft.update(val_to_remove, -(int)indices_to_delete.size());
        cnt[val_to_remove] = 0;

        for (int idx : indices_to_delete) {
            int pr = prev[idx];
            int nx = next[idx];
            next[pr] = nx;
            prev[nx] = pr;
        }
    }
    
    // --- Final Check: See if remaining elements form a palindrome ---
    vector<int> remaining;
    int current_idx = next[0];
    while(current_idx <= n) {
        remaining.push_back(a[current_idx]);
        current_idx = next[current_idx];
    }
    
    bool is_pal = true;
    for(size_t i = 0; i < remaining.size() / 2; ++i) {
        if (remaining[i] != remaining[remaining.size() - 1 - i]) {
            is_pal = false;
            break;
        }
    }
    
    cout << (is_pal ? "YES\n" : "NO\n");
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}