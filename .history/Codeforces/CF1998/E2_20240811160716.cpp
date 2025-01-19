#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Info {int maxn = 0;};
Info operator + (const Info & x, const Info & y) {return {max(x.maxn, y.maxn)};}
template<class Info>
struct segmentTree {
    int n;
    vector<Info> info;
    segmentTree() {}
    segmentTree(int n, Info _init = Info()) {
        init(vector<Info>(n, _init));
    }
    segmentTree(const vector<Info> & _init) {
        init(_init());
    }
    void init(const vector<Info> & _init) {
        n = (int)_init.size();
        info.assign((n << 2) + 1, Info());
        function<void(int, int, int)> build = [&](int p, int pl, int pr) {
            if (pl == pr) {
                info[p] = _init[pl - 1];
                return;
            }
            int mid = pl + pr >> 1;
            build(p << 1, pl, mid);
            build(p << 1 | 1, mid + 1, pr);
            pushUp(p);
        };
        build(1, 1, n);
    }
    void pushUp(int p) {info[p] = info[p << 1] + info[p << 1 | 1];}
    void modify(int p, int pl, int pr, int x, const Info & v) {
        if (pl == pr) {
            info[p] = v;
            return;
        }
        int mid = pl + pr >> 1;
        if (x <= mid) modify(p << 1, pl, mid, x, v);
        else modify(p << 1 | 1, mid + 1, pr, x, v);
        pushUp(p);
    }
    void modify(int x, const Info & v) {modify(1, 1, n, x, v);}
    Info query(int L, int R, int p, int pl, int pr) {
        if (pl > R || pr < L) {return Info();}
        if (L <= pl && pr <= R) {return info[p];}
        int mid = pl + pr >> 1;
        return query(L, R, p << 1, pl, mid) + query(L, R, p << 1 | 1, mid + 1, pr);
    }
    Info query(int L, int R) {query(L, R, 1, 1, n);}
    int findFirst(int L, int R, int p, int pl, int pr, const function<bool(const Info &)> & f, Info & pre) {
        if (pl > R || pr < L) {return R + 1;}
        if (L <= pl && pr <= R) {
            if (!f(pre + info[p])) {
                pre = pre + info(p);
                return R + 1;
            }
            if (pl == pr) return pr;
            int mid = pl + pr >> 1, res;
            if (f(pre + info[p << 1])) res = findFirst(L, R, p << 1, pl, mid, f, pre);
            else {
                pre = pre + info[p << 1];
                res = findFirst(L, R, p << 1 | 1, mid + 1, pr, f, pre);
            }
            return res;
        }
        int mid = pl + pr >> 1, res = mid + 1;
        if (L <= mid) res = findFirst(L, R, p << 1, pl, mid, f, pre);
        if (R > mid && res == mid + 1) res = findFirst(L, R, p << 1 | 1, mid + 1, pr, f, pre);
        return res;
    }
    int findFirst(int L, int R, const function<bool(const Info &)> & f) {
        Info pre = Info();
        return findFirst(L, R, 1, 1, n, f, pre);
    }
    int findLast(int L, int R, int p, int pl, int pr, const function<bool(const Info &)> & f, Info & suf) {
        if (pl > R || pr < L) {return L - 1;}
        if (L <= pl && pr <= R) {
            if (!f(info[p] + suf)) {
                suf = info[p] + suf;
                return L - 1;
            }
            if (pl == pr) return pr;
            int mid = pl + pr >> 1, res;
            if (f(info[p << 1] + suf)) res = findLast(L, R, p << 1, pl, mid, f, suf);
            else {
                suf = info[p] + suf;
                res = findLast(L, R, p << 1 | 1, mid + 1, pr, f, suf);
            }
        }
        int mid = pl + pr >> 1, res = mid;
        if (R > mid) res = findLast(L, R, p << 1 | 1, mid + 1, pr, f, suf);
        if (L <= mid && res == mid) res = findLast(L, R, p << 1, pl, mid, f, suf);
        return res;
    }
    int findLast(int L, int R, const function<bool(const Info &)> & f) {
        Info suf = Info();
        return findLast(L, R, 1, 1, n, f, suf);
    }
};
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n + 2);
    vector<Info> init(n);
    vector<int> s(n + 1);
    for (int i = 1 ; i <= n; ++ i) {
        cin >> a[i];
        init[i - 1] = {a[i]};
        s[i] = s[i - 1] + a[i];
    }
    vector<int> ans(n + 1);
    auto add = [&](int l, int r) {
        if (l > r) return;
        ans[l] += 1;
        if (r + 1 <= n) ans[r + 1] -= 1;
    };
    segmentTree<Info> seg(init);
    for (int i = 1; i <= n; ++ i) {
        vector<int> ls{i}, rs{i};
        while (ls.back() != 0) {
            if (ls.back() == 1) {
                ls.emplace_back(0);
                break;
            }
            int sum = s[i] - s[ls.back() - 1];
            auto f = [&](const Info & info) {return info.maxn > sum;};
            int pos = seg.findLast(1, ls.back() - 1, f);
            ls.emplace_back(pos);
        }
        reverse(ls.begin(), ls.end());
        while (rs.back() != n + 1) {
            if (rs.back() == n) {
                rs.emplace_back(n + 1);
                break;
            }
            int sum = s[rs.back()] - s[i - 1];
            auto f = [&](const Info & info) {return info.maxn > sum;};
            int pos = seg.findFirst(rs.back() + 1, n, f);
            rs.emplace_back(pos);
        }
        {
            for (int k = 0, j = (int)ls.size() - 1; k + 1 < rs.size(); ++ k) {
                int L = rs[k], R = rs[k + 1] - 1;
                while (j - 1 >= 0 && s[L] - s[ls[j - 1]] >= a[ls[j - 1]]) j --;
                if (j == 0) add(L, R);
                else {
                    auto check = [&](int mid) {
                        for (int k = j; k >= 1; -- k)
                            if (s[mid] - s[ls[k - 1]] < a[ls[k - 1]]) return false;
                        return true;
                    };
                    int l = L, r = R + 1;
                    while (l < r) {
                        int mid = l + r >> 1;
                        if (check(mid)) r = mid;
                        else l = mid + 1;
                    }
                    add(r, R);
                }
            }
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}