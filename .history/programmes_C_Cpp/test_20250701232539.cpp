#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, k;
        string s;
        cin >> n >> k >> s;

        // 1) 统计总 1 数
        vector<int> pref(n+1, 0);
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + (s[i]=='1');
        }
        int m = pref[n];

        // Alice 一回合能清完
        if(m <= k){
            cout << "Alice\n";
            continue;
        }

        // Bob 能否找到一个长度-k 的子串，其两侧的 1 数 ≥ k？
        bool bobWins = false;
        // 枚举子串起点 i: [i, i+k-1]
        for(int i = 0; i + k <= n; i++){
            int onesLeft  = pref[i];               // [0..i-1] 里的 1
            int onesRight = pref[n] - pref[i+k];   // [i+k..n-1] 里的 1
            if(onesLeft + onesRight >= k){
                bobWins = true;
                break;
            }
        }

        cout << (bobWins ? "Bob\n" : "Alice\n");
    }
    return 0;
}
