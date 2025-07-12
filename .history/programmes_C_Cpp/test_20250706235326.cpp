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
        
        // Case k == 1: always possible (empty palindrome)
        if (k == 1) {
            cout << "YES\n";
            continue;
        }
        
        // Check if already a palindrome
        bool is_pal = true;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (a[i] != a[j]) {
                is_pal = false;
                break;
            }
        }
        if (is_pal) {
            cout << "YES\n";
            continue;
        }
        
        // Build the multiset of the smallest k-1 elements
        vector<int> b = a;
        sort(b.begin(), b.end());
        int h = k - 1;
        vector<int> K(b.begin(), b.begin() + h);
        
        // Count odd frequencies
        unordered_map<int,int> freq;
        freq.reserve(h * 2);
        int odd_cnt = 0;
        for (int v : K) {
            if ((freq[v] & 1) == 1) {
                odd_cnt--; // was odd, now even
            } else {
                odd_cnt++; // was even (or zero), now odd
            }
            freq[v]++;
        }
        if (odd_cnt > 1) {
            cout << "NO\n";
            continue;
        }
        
        // Build one palindrome P from multiset K
        vector<int> half;
        int m = K.size();
        int mid = -1;
        if (m % 2 == 1) {
            mid = K[m / 2];
        }
        for (int i = 0; i < m/2; i++) {
            half.push_back(K[i]);
        }
        vector<int> P = half;
        if (mid != -1) P.push_back(mid);
        for (int i = (int)half.size() - 1; i >= 0; i--) {
            P.push_back(half[i]);
        }
        
        // Check if P is a subsequence of a
        int j = 0;
        for (int i = 0; i < n && j < (int)P.size(); i++) {
            if (a[i] == P[j]) {
                j++;
            }
        }
        
        cout << (j == (int)P.size() ? "YES" : "NO") << "\n";
    }

    return 0;
}
