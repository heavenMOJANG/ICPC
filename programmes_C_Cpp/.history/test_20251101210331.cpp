#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using pii = pair<int,int>;

// 节点类型：区间内最大值和达到最大值的位置数量
struct Node {
    int mx, cnt;
};

// 操作函数与单位元
Node op(const Node &a, const Node &b){
    if(a.mx == b.mx) return {a.mx, a.cnt + b.cnt};
    return (a.mx > b.mx) ? a : b;
}
Node e(){ return Node{ INT_MIN/4, 0 }; } // identity for op

// 懒操作：F 为 int（表示加到 mx 上的值）
using F = int;
Node mapping(const F &f, const Node &x){
    return { x.mx + f, x.cnt };
}
F composition(const F &f, const F &g){ // first apply g then f -> addition is commutative: f+g
    return f + g;
}
F id(){ return 0; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    if(!(cin >> N >> Q)) return 0;

    // 初始化线段树：每个位置初始为 (mx=0, cnt=1)
    vector<Node> init(N);
    for(int i=0;i<N;++i) init[i] = Node{0,1};
    atcoder::lazy_segtree<Node, op, e, F, mapping, composition, id> seg(init);

    const int MAXX = 60;
    vector< set<pii> > st(MAXX+1); // st[x] 保存所有包含 x 的互不重叠区间 [l,r]

    for(int qi=0; qi<Q; ++qi){
        int type; cin >> type;
        if(type == 1){
            int L,R,x; cin >> L >> R >> x;
            // 将 [L,R] 加入 st[x]，并对原先没有 x 的区间在 seg 上 +1
            auto &S = st[x];
            int a = L, b = R;
            // 找第一个可能重叠或相邻的区间
            auto it = S.lower_bound({L, -1});
            if(it != S.begin()){
                auto pit = it; --pit;
                if(pit->second >= L-1) it = pit;
            }
            int cur = L;
            int newL = L, newR = R;
            vector<pii> toerase;
            while(it != S.end() && it->first <= R+1){
                int s = it->first, t = it->second;
                newL = min(newL, s);
                newR = max(newR, t);
                if(s > cur){
                    int addL = cur;
                    int addR = min(s-1, R);
                    if(addL <= addR) seg.apply(addL-1, addR-1, +1); // 注意 lazy_segtree 的 apply 接口用 index 从 0 开始，如果使用 apply 单点则不同；这里改用 range: we'll call seg.apply? -> we will instead use seg.apply(range) below
                }
                cur = max(cur, t+1);
                toerase.push_back(*it);
                ++it;
            }
            if(cur <= R){
                seg.apply(cur-1, R-1, +1);
            }
            for(auto &p: toerase) S.erase(p);
            S.insert({newL, newR});

        } else if(type == 2){
            int L,R,x; cin >> L >> R >> x;
            auto &S = st[x];
            if(S.empty()) continue;
            // 从第一个可能重叠的区间开始
            auto it = S.lower_bound({L+1, -1});
            if(it != S.begin()) --it;
            else it = S.begin();
            vector<pii> toerase;
            vector<pii> toadd;
            while(it != S.end()){
                int s = it->first, t = it->second;
                if(s > R) break;
                if(t < L){
                    ++it; continue;
                }
                int ol = max(s, L);
                int orr = min(t, R);
                if(ol <= orr){
                    seg.apply(ol-1, orr-1, -1);
                }
                if(s < ol) toadd.push_back({s, ol-1});
                if(t > orr) toadd.push_back({orr+1, t});
                toerase.push_back(*it);
                ++it;
            }
            for(auto &p: toerase) S.erase(p);
            for(auto &p: toadd) S.insert(p);
        } else if(type == 3){
            int L,R; cin >> L >> R;
            auto res = seg.prod(L-1, R); // prod returns Node over [l,r)
            cout << res.mx << " " << res.cnt << "\n";
        }
    }
    return 0;
}
