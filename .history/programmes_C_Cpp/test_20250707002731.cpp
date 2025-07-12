#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree for frequencies on [1..M]
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n):n(_n),f(n+1,0){}
    // add v at index i
    void update(int i, int v){
        for(; i<=n; i+=i&-i) f[i]+=v;
    }
    // sum of [1..i]
    int query(int i){
        int s=0;
        for(; i>0; i-=i&-i) s+=f[i];
        return s;
    }
    // sum of [l..r]
    int query(int l, int r){
        if(l>r) return 0;
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        // k=1 时可随意删任何元素 → 一定能凑回文
        if(k == 1){
            cout << "YES\n";
            continue;
        }

        // 离散化或直接 since a[i] ≤ n，可直接建到 n
        Fenwick fw(n);
        vector<int> freq(n+1,0);
        for(int x: a){
            fw.update(x, 1);
            freq[x]++;
        }

        int l = 0, r = n-1;
        bool ok = false;
        while(true){
            if(l >= r){
                ok = true;
                break;
            }
            if(a[l] == a[r]){
                // “匹配”这一对
                fw.update(a[l], -1);
                fw.update(a[r], -1);
                freq[a[l]]--;
                freq[a[r]]--;
                l++;
                r--;
                continue;
            }
            int len = r - l + 1;
            bool delL = false, delR = false;
            if(len >= k){
                // 尝试删左端
                int x = a[l];
                int cntLess = fw.query(x-1);
                int cntEq   = freq[x];
                if(cntLess < k && k <= cntLess + cntEq){
                    delL = true;
                } else {
                    // 尝试删右端
                    int y = a[r];
                    int cntLessR = fw.query(y-1);
                    int cntEqR   = freq[y];
                    if(cntLessR < k && k <= cntLessR + cntEqR)
                        delR = true;
                }
            }
            if(delL){
                // 从区间里删掉 a[l]
                fw.update(a[l], -1);
                freq[a[l]]--;
                l++;
            }
            else if(delR){
                fw.update(a[r], -1);
                freq[a[r]]--;
                r--;
            }
            else{
                // 两端都删不了 → 失败
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
