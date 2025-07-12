#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 情况1：k == 1，总能删空得到空数组（视为回文）
        if(k == 1){
            cout << "YES\n";
            continue;
        }

        // 统计所有值的频次，并按值升序遍历累加，找到最大的 X 使得累加 < k
        map<int,int> cnt;
        for(int v : a) cnt[v]++;
        int cum = 0;
        int X = -1;  // 阈值
        for(auto [v, f] : cnt){
            if(cum + f < k){
                cum += f;
                X = v;
            } else {
                break;
            }
        }
        // 如果 X = -1，说明最小的那个值都无法保底，也就是连最小的都能被删，
        // 最后剩下至多 k-1 个元素，但它们是删出来的，且必然是回文（1～k-1 次删操作不会打散）
        if(X == -1){
            cout << "YES\n";
            continue;
        }

        // 构造锚点子序列 b
        vector<int> b;
        for(int v : a){
            if(v <= X){
                b.push_back(v);
            }
        }

        int m = (int)b.size();
        // 如果锚点长度小于 k-1，就不可能删到长度 < k
        if(m < k - 1){
            cout << "NO\n";
            continue;
        }
        // 检查 b 是否回文
        bool ok = true;
        for(int i = 0, j = m-1; i < j; i++, j--){
            if(b[i] != b[j]){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
