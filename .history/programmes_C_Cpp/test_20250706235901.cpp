#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // If k == 1, we can delete anything to empty
        if (k == 1) {
            cout << "YES\n";
            continue;
        }
        
        // Check if already a palindrome
        bool pal = true;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (a[i] != a[j]) { pal = false; break; }
        }
        if (pal) {
            cout << "YES\n";
            continue;
        }
        
        // Sort a copy to find k-th smallest
        vector<int> b = a;
        sort(b.begin(), b.end());
        int val = b[k-1];
        // Count elements < val, == val
        int c_less = lower_bound(b.begin(), b.end(), val) - b.begin();
        int c_eq   = upper_bound(b.begin(), b.end(), val) - b.begin() - c_less;
        
        // Build multiset K: all <val, plus one val if c_eq is odd
        vector<int> K;
        K.reserve(c_less + (c_eq % 2));
        for (int x : b) {
            if (x < val) K.push_back(x);
        }
        if (c_eq % 2 == 1) K.push_back(val);
        
        // Check odd counts in K (should be <=1)
        unordered_map<int,int> freq;
        freq.reserve(K.size()*2);
        int oddc = 0;
        for (int x : K) {
            if (freq[x] % 2 == 0) oddc++;
            else oddc--;
            freq[x]++;
        }
        if (oddc > 1) {
            cout << "NO\n";
            continue;
        }
        
        // Build one palindrome P from K
        vector<int> half;
        int mid = -1;
        for (auto &p : freq) {
            if (p.second % 2 == 1) mid = p.first;
            // push p.second/2 copies into half
        }
        for (auto &p : freq) {
            int times = p.second / 2;
            for (int t = 0; t < times; ++t) half.push_back(p.first);
        }
        sort(half.begin(), half.end());
        vector<int> P = half;
        if (mid != -1) P.push_back(mid);
        for (int i = (int)half.size() - 1; i >= 0; --i) P.push_back(half[i]);
        
        // Check P is subsequence of a
        int j = 0;
        for (int i = 0; i < n && j < (int)P.size(); ++i) {
            if (a[i] == P[j]) ++j;
        }
        cout << (j == (int)P.size() ? "YES" : "NO") << "\n";
    }
    return 0;
}
