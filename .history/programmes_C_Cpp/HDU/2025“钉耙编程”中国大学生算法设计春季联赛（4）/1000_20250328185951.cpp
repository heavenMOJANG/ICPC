#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
namespace lazysegtree {
	int ceil_pow2(int n) {
		int x = 0;
		while ((1U << x) < (unsigned int)(n)) x++;
		return x;
	}
	template <class S,
		S(*op)(S, S),
		S(*e)(),
		class F,
		S(*mapping)(F, S),
		F(*composition)(F, F),
		F(*id)()>
		struct lazy_segtree {
		public:
			lazy_segtree() : lazy_segtree(0) {}
			explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
			explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
				log = ceil_pow2(_n);
				size = 1 << log;
				d = std::vector<S>(2 * size, e());
				lz = std::vector<F>(size, id());
				for (int i = 0; i < _n; i++) d[size + i] = v[i];
				for (int i = size - 1; i >= 1; i--) {
					update(i);
				}
			}

			void set(int p, S x) {
				assert(0 <= p && p < _n);
				p += size;
				for (int i = log; i >= 1; i--) push(p >> i);
				d[p] = x;
				for (int i = 1; i <= log; i++) update(p >> i);
			}

			S get(int p) {
				assert(0 <= p && p < _n);
				p += size;
				for (int i = log; i >= 1; i--) push(p >> i);
				return d[p];
			}

			S prod(int l, int r) {
				assert(0 <= l && l <= r && r <= _n);
				if (l == r) return e();

				l += size;
				r += size;

				for (int i = log; i >= 1; i--) {
					if (((l >> i) << i) != l) push(l >> i);
					if (((r >> i) << i) != r) push((r - 1) >> i);
				}

				S sml = e(), smr = e();
				while (l < r) {
					if (l & 1) sml = op(sml, d[l++]);
					if (r & 1) smr = op(d[--r], smr);
					l >>= 1;
					r >>= 1;
				}

				return op(sml, smr);
			}

			S all_prod() { return d[1]; }

			void apply(int p, F f) {
				assert(0 <= p && p < _n);
				p += size;
				for (int i = log; i >= 1; i--) push(p >> i);
				d[p] = mapping(f, d[p]);
				for (int i = 1; i <= log; i++) update(p >> i);
			}
			void apply(int l, int r, F f) {
				assert(0 <= l && l <= r && r <= _n);
				if (l == r) return;

				l += size;
				r += size;

				for (int i = log; i >= 1; i--) {
					if (((l >> i) << i) != l) push(l >> i);
					if (((r >> i) << i) != r) push((r - 1) >> i);
				}

				{
					int l2 = l, r2 = r;
					while (l < r) {
						if (l & 1) all_apply(l++, f);
						if (r & 1) all_apply(--r, f);
						l >>= 1;
						r >>= 1;
					}
					l = l2;
					r = r2;
				}

				for (int i = 1; i <= log; i++) {
					if (((l >> i) << i) != l) update(l >> i);
					if (((r >> i) << i) != r) update((r - 1) >> i);
				}
			}

			template <bool(*g)(S)> int max_right(int l) {
				return max_right(l, [](S x) { return g(x); });
			}
			template <class G> int max_right(int l, G g) {
				assert(0 <= l && l <= _n);
				assert(g(e()));
				if (l == _n) return _n;
				l += size;
				for (int i = log; i >= 1; i--) push(l >> i);
				S sm = e();
				do {
					while (l % 2 == 0) l >>= 1;
					if (!g(op(sm, d[l]))) {
						while (l < size) {
							push(l);
							l = (2 * l);
							if (g(op(sm, d[l]))) {
								sm = op(sm, d[l]);
								l++;
							}
						}
						return l - size;
					}
					sm = op(sm, d[l]);
					l++;
				} while ((l & -l) != l);
				return _n;
			}

			template <bool(*g)(S)> int min_left(int r) {
				return min_left(r, [](S x) { return g(x); });
			}
			template <class G> int min_left(int r, G g) {
				assert(0 <= r && r <= _n);
				assert(g(e()));
				if (r == 0) return 0;
				r += size;
				for (int i = log; i >= 1; i--) push((r - 1) >> i);
				S sm = e();
				do {
					r--;
					while (r > 1 && (r % 2)) r >>= 1;
					if (!g(op(d[r], sm))) {
						while (r < size) {
							push(r);
							r = (2 * r + 1);
							if (g(op(d[r], sm))) {
								sm = op(d[r], sm);
								r--;
							}
						}
						return r + 1 - size;
					}
					sm = op(d[r], sm);
				} while ((r & -r) != r);
				return 0;
			}

		private:
			int _n, size, log;
			std::vector<S> d;
			std::vector<F> lz;

			void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
			void all_apply(int k, F f) {
				d[k] = mapping(f, d[k]);
				if (k < size) lz[k] = composition(f, lz[k]);
			}
			void push(int k) {
				all_apply(2 * k, lz[k]);
				all_apply(2 * k + 1, lz[k]);
				lz[k] = id();
			}
	};

}
int op(int a, int b) { return a + b; }
int e() { return -1e9; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }
void solve() {
    int n, q; cin >> n >> q;
    lazysegtree::lazy_segtree<int, op, e, int, mapping, composition, id> seg(n + 1);
    for (int i = 1, x; i <= n; ++ i) cin >> x, seg.set(i, x);
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 1) seg.set(x, y);
        else {
            int l = seg.prod(1, x) / 100, r = seg.prod(1, y + 1) / 100;
            cout << r - l << "\n";
            ans ^= (r - l) * i;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}