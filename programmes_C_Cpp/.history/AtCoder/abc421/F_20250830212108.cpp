#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 10;
struct Node {
    int ls, rs, fa;
    int pri;
    int size;
    int key;
    int sum;
} tr[N];
int Q, rt{};
int siz(int x){ return x ? tr[x].size : 0ll; }
int sum(int x){ return x ? tr[x].sum : 0ll; }
void insert(int u){
    if(!u) return;
    tr[u].size = 1 + siz(tr[u].ls) + siz(tr[u].rs);
    tr[u].sum = tr[u].key + sum(tr[u].ls) + sum(tr[u].rs);
    if(tr[u].ls) tr[tr[u].ls].fa = u;
    if(tr[u].rs) tr[tr[u].rs].fa = u;
}
void newNode(int id, int val){
    tr[id].ls = tr[id].rs = tr[id].fa = 0;
    tr[id].pri = rand();
    tr[id].size = 1;
    tr[id].key = val;
    tr[id].sum = val;
}
void split(int p, int k, int& l, int& r){
    if (p == 0){ l = r = 0; return; }
    if (siz(tr[p].ls) >= k) {
        int nl;
        split(tr[p].ls, k, l, nl);
        tr[p].ls = nl;
        if(nl) tr[nl].fa = p;
        tr[p].fa = 0;
        r = p;
        insert(r);
    } else {
        int nr;
        split(tr[p].rs, k - siz(tr[p].ls) - 1, nr, r);
        tr[p].rs = nr;
        if(nr) tr[nr].fa = p;
        tr[p].fa = 0;
        l = p;
        insert(l);
    }
}
int merge(int a, int b){
    if (!a || !b) {
        int p = a + b;
        if(p) tr[p].fa = 0;
        return p;
    }
    if (tr[a].pri > tr[b].pri) {
        tr[a].rs = merge(tr[a].rs, b);
        if(tr[a].rs) tr[tr[a].rs].fa = a;
        insert(a);
        tr[a].fa = 0;
        return a;
    } else {
        tr[b].ls = merge(a, tr[b].ls);
        if(tr[b].ls) tr[tr[b].ls].fa = b;
        insert(b);
        tr[b].fa = 0;
        return b;
    }
}
int kth(int x){
    int idx = siz(tr[x].ls), cur = x;
    while(tr[cur].fa){
        int res = tr[cur].fa;
        if(cur == tr[res].rs) idx += 1 + siz(tr[res].ls);
        cur = res;
    }
    return idx;
}
signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    srand(time(nullptr));
    cin >> Q;
    newNode(1, 0);
    rt = 1;
    for(int i = 1; i <= Q; ++ i){
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            newNode(i + 1, i);
            int idx = kth(x + 1);
            int a, b;
            split(rt, idx + 1, a, b);
            int t = merge(a, i + 1);
            rt = merge(t, b);
        } else {
            int x, y; cin >> x >> y;
            int kx = kth(x + 1), ky = kth(y + 1);
            int l = min(kx, ky), r = max(kx, ky);
            int a, b;
            split(rt, l + 1, a, b);
            int len = r - l - 1;
            if(len > 0){
                int mid, c;
                split(b, len, mid, c);
                int ans = sum(mid);
                rt = merge(a, c);
                cout << ans << "\n";
            } else {
                rt = merge(a, b);
                cout << "0\n";
            }
        }
    }
    return 0;
}