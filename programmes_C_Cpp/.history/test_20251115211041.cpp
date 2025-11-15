#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct S { int lx, rx, ly, ry; };
void solve() {
    int N; int X, Y;
    cin >> N >> X >> Y;
    vector<tuple<char,int,int>> storms(N);
    for (auto& [ch,a,b] : storms) cin >> ch >> a >> b;
    vector<S> rects = {{0, X - 1, 0, Y - 1}};

    for (auto [ch,A,B] : storms) {
        vector<S> next;
        int d1 = -B, d2 = B;
        for (auto r : rects) {
            int xl = r.lx, xr = r.rx, yl = r.ly, yr = r.ry;
            if (ch == 'X') {
                int al = min(xr, A-1);
                if (xl <= al) next.push_back({xl, al, yl + d1, yr + d1});
                int ar = max(xl, A);
                if (ar <= xr) next.push_back({ar, xr, yl + d2, yr + d2});
            } else { // 'Y'
                int al = min(yr, A-1);
                if (yl <= al) next.push_back({xl + d1, xr + d1, yl, al});
                int ar = max(yl, A);
                if (ar <= yr) next.push_back({xl + d2, xr + d2, ar, yr});
            }
        }
        rects = move(next);
    }

    int n = rects.size();
    vector<int> area(n,0);
    for (int i=0;i<n;i++){
        int w = rects[i].rx - rects[i].lx + 1;
        int h = rects[i].ry - rects[i].ly + 1;
        if (w>0 && h>0) area[i] = w*h;
    }

    // 并查集
    vector<int> P(n);
    iota(P.begin(),P.end(),0);
    function<int(int)> find = [&](int x){
        return P[x] == x ? x : P[x] = find(P[x]);
    };
    auto unite = [&](int a,int b){
        a = find(a); b = find(b);
        if (a != b) P[b] = a;
    };

    for (int i=0;i<n;i++) if (area[i]>0){
        for (int j=i+1;j<n;j++) if (area[j]>0){
            auto &ra = rects[i], &rb = rects[j];
            int x1a=ra.lx, x1b=ra.rx, y1a=ra.ly, y1b=ra.ry;
            int x2a=rb.lx, x2b=rb.rx, y2a=rb.ly, y2b=rb.ry;
            bool h = (x1b+1==x2a || x2b+1==x1a) && max(y1a,y2a) <= min(y1b,y2b);
            bool v = (y1b+1==y2a || y2b+1==y1a) && max(x1a,x2a) <= min(x1b,x2b);
            if (h || v) unite(i,j);
        }
    }

    map<int,int> M;
    for (int i=0;i<n;i++) if (area[i]>0){
        int r = find(i);
        M[r] += area[i];
    }

    cout << M.size() << "\n";
    vector<int> ans;
    for (auto &[k,v]:M) ans.push_back(v);
    sort(ans.begin(),ans.end());
    for (size_t i=0;i<ans.size();i++){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
