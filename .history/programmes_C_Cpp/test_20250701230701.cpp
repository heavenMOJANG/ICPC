#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        vector<int> mn(n), mx(n);
        // 前缀最小
        mn[0] = a[0];
        for(int i=1;i<n;i++){
            mn[i] = min(mn[i-1], a[i]);
        }
        // 后缀最大
        mx[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            mx[i] = max(mx[i+1], a[i]);
        }

        // 构造答案
        string ans(n, '0');
        for(int i=0;i<n;i++){
            if (a[i] == mn[i] || a[i] == mx[i]) {
                ans[i] = '1';
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
