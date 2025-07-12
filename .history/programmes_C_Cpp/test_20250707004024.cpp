#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n/2; i++){
        if(a[i] != a[n-1-i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        // 情况1: 原数组已回文 或 k=1
        if(k == 1 || isPalindrome(a)) {
            cout<<"YES\n";
            continue;
        }

        // 统计值的出现频次，并计算阈值X
        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());
        int cnt = 0, X = 0;
        for(int x : sorted){
            cnt++;
            if(cnt < k) {
                X = x;
            } else {
                break;
            }
        }
        // 如果所有值累加都 >= k，则 X=0 表示所有值可删
        if(cnt < k) X = sorted.back();
        
        // 统计锚值频次
        unordered_map<int,int> freq;
        for(int x : a){
            if(x <= X){
                freq[x]++;
            }
        }
        // 统计出现奇数次的锚值个数
        int oddCount = 0;
        int oddVal = -1;
        for(auto &p : freq){
            if(p.second % 2 == 1){
                oddCount++;
                oddVal = p.first;
            }
        }
        if(oddCount > 1){
            cout<<"NO\n";
            continue;
        }
        if(oddCount == 0){
            // 所有锚值偶数次，可两两配对
            cout<<"YES\n";
            continue;
        }
        // oddCount == 1
        // 找到值 oddVal 在原数组的所有位置
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(a[i] == oddVal) pos.push_back(i);
        }
        bool ok = false;
        // 检查是否存在公共非锚值可配对
        for(int center : pos){
            unordered_set<int> leftVals, rightVals;
            for(int i = 0; i < center; i++){
                if(a[i] > X) leftVals.insert(a[i]);
            }
            for(int i = center+1; i < n; i++){
                if(a[i] > X) {
                    rightVals.insert(a[i]);
                }
            }
            // 查找左右有无相同值
            for(int v : leftVals){
                if(rightVals.count(v)) {
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
