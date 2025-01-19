#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector<int>pre(n + 5), suf(n + 5), pos1, pos2, cnt1(n + 5), cnt2(n + 5), ans(n + 5);
    
    for(int i = 1;i <= n;i++){
        if(s[i] == '>') pre[i] = i, cnt1[i] = 1;
        else suf[i] = i, cnt2[i] = 1;
    }
    for(int i = 1;i <= n;i++){
        cnt1[i] += cnt1[i - 1];
        if(s[i] == '>') pos1.push_back(i);
    }
    for(int i = n;i >= 1;i--){
        cnt2[i] += cnt2[i + 1];
        if(s[i] == '<' ) pos2.push_back(i);
    }
    
    for(int i = 1;i <= n;i++)
        pre[i] += pre[i - 1];
    for(int i = n;i >= 1;i--)
        suf[i] += suf[i + 1];
    for(int i = 1;i <= n;i++){
        if(s[i] == '<'){
            if(cnt1[i - 1] > cnt2[i + 1]){ // 从右出去
                int k = cnt2[i + 1];
                int num1;
                if(cnt1[i - 1] - k - 1 - 1 == -1)
                    num1 = pre[i - 1];
                else
                    num1 = pre[i - 1] - pre[pos1[cnt1[i - 1] - k - 1 - 1]];
                int num2 = suf[i + 1];
                ans[i] = i + n + 1 + 2 * num2 - 2 * num1;
            }
            else if(cnt1[i - 1] < cnt2[i + 1]){//从左出去
                int k = cnt1[i - 1];
                int num1 = pre[i - 1];
                int num2 = suf[i + 1] - suf[pos2[cnt2[i + 1] - k - 1]];
                ans[i] = i + 2 * num2 - 2 * num1;
            }
            else{
                int k = cnt1[i - 1];
                int num1 = pre[i - 1];
                int num2 = suf[i + 1];
                ans[i] = i + 2 * num2 - 2 * num1;
            }
            
        }
        else{
            if(cnt1[i - 1] < cnt2[i + 1]){//从左出去
                int k = cnt1[i - 1];
                int num1 = pre[i - 1];
                int num2;
                if(cnt2[i + 1] - k - 1 - 1 == -1)
                    num2 = suf[i + 1];
                else
                    num2 = suf[i + 1] - suf[pos2[cnt2[i + 1] - k - 1 - 1]];
                ans[i] = 2 * num2 - 2 * num1 - i;
            }
            else if(cnt1[i - 1] > cnt2[i + 1]){// 从右出去
                int k = cnt2[i + 1];
                int num1 = pre[i - 1] - pre[pos1[cnt1[i - 1] - k - 1]];
                int num2 = suf[i + 1];
                ans[i] = n + 1 - i + 2 * num2 - 2 * num1;
            }
            else{
                int k = cnt2[i + 1];
                int num1 = pre[i - 1];
                int num2 = suf[i + 1];
                ans[i] = n + 1 - i + 2 * num2 - 2 * num1;
            }
        }
    }
    for(int i = 1;i <= n;i++)
        cout << ans[i] << " ";
    cout << endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
