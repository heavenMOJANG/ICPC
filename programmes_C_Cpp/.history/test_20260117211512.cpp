// g++ -std=c++17 -O2 -march=native your.cpp
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using namespace atcoder;

struct S {
    ll mx;    // maximum takoyaki among plates that are face-up in this segment
    ll cnt;   // number of face-up plates in this segment
    ll len;   // segment length
};
struct F {
    ll add;   // add to face-up plates
    bool flip; // perform "eat all (set to 0) then flip" in this segment
};

// op: merge two nodes
S op(const S &a, const S &b) {
    return S{ max(a.mx, b.mx), a.cnt + b.cnt, a.len + b.len };
}
S e() { return S{0LL, 0LL, 0LL}; }

// mapping: apply lazy f to node s
S mapping(const F &f, const S &s) {
    S res = s;
    if (f.flip) {
        // "eat all then flip": all values become 0, and face-up count toggles
        res.mx = 0;
        res.cnt = res.len - res.cnt;
    }
    if (f.add != 0 && res.cnt > 0) {
        // add to all face-up plates => maximum among face-up increases by add
        res.mx += f.add;
    }
    return res;
}

// composition: return f ∘ g, i.e. applying g then f is same as applying h = composition(f,g)
F composition(const F &f, const F &g) {
    F h;
    // final flip is xor
    h.flip = f.flip ^ g.flip;
    if (f.flip) {
        // if f.flip true, f will zero values after g is applied => any prior adds from g are lost
        // so only the add from f remains (applied after flipping)
        h.add = f.add;
    } else {
        // if f does not flip, then adds accumulate: first g.add then f.add
        h.add = g.add + f.add;
    }
    return h;
}
F id() { return F{0LL, false}; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<S> init(N);
    for (int i = 0; i < N; ++i) init[i] = S{0LL, 1LL, 1LL}; // initially all face-up, zero takoyaki

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);

    for (int qi = 0; qi < Q; ++qi) {
        int t; cin >> t;
        if (t == 1) {
            int L, R; ll X; cin >> L >> R >> X;
            seg.apply(L-1, R, F{X, false});
        } else if (t == 2) {
            int L, R; cin >> L >> R;
            seg.apply(L-1, R, F{0LL, true});
        } else if (t == 3) {
            int L, R; cin >> L >> R;
            cout << seg.prod(L-1, R).mx << '\n';
        }
    }
    return 0;
}
