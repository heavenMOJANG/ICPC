#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

bool check(const std::vector<int>& v) {
    if (v.size() < 5) {
        return false;
    }
    bool inc = true;
    bool dec = true;
    for (size_t i = v.size() - 5; i < v.size() - 1; ++i) {
        if (v[i] >= v[i + 1]) {
            inc = false;
        }
        if (v[i] <= v[i + 1]) {
            dec = false;
        }
    }
    return inc || dec;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    int l = 0, r = n - 1;
    std::vector<int> q;
    std::string s;
    q.reserve(n);
    s.reserve(n);

    while (l <= r) {
        if (l == r) {
            s += 'L';
            break;
        }

        bool bad_l = false;
        q.push_back(p[l]);
        if (check(q)) {
            bad_l = true;
        }
        q.pop_back();

        bool bad_r = false;
        q.push_back(p[r]);
        if (check(q)) {
            bad_r = true;
        }
        q.pop_back();

        char choice;
        if (bad_l && bad_r) {
            // 根据题目保证，这种情况不会发生
        } else if (bad_l) {
            choice = 'R';
        } else if (bad_r) {
            choice = 'L';
        } else {
            int c1 = 0;
            q.push_back(p[l]);
            if (l < r) {
                q.push_back(p[l + 1]);
                if (!check(q)) c1++;
                q.pop_back();
                if (l + 1 < r) {
                    q.push_back(p[r]);
                    if (!check(q)) c1++;
                    q.pop_back();
                }
            }
            q.pop_back();

            int c2 = 0;
            q.push_back(p[r]);
            if (l < r) {
                q.push_back(p[l]);
                if (!check(q)) c2++;
                q.pop_back();
                if (l < r - 1) {
                    q.push_back(p[r - 1]);
                    if (!check(q)) c2++;
                    q.pop_back();
                }
            }
            q.pop_back();

            if (c1 > c2) {
                choice = 'L';
            } else if (c2 > c1) {
                choice = 'R';
            } else {
                choice = 'L'; 
            }
        }

        if (choice == 'L') {
            q.push_back(p[l]);
            s += 'L';
            l++;
        } else {
            q.push_back(p[r]);
            s += 'R';
            r--;
        }
    }
    std::cout << s << std::endl;
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