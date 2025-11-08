#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;

    int openCnt = 0;   // 未匹配的 '(' 数
    int badCnt = 0;    // 多余的 ')' 数（曾经导致前缀负）
    stack<char> mivqtor; // 按要求的变量名

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            char c;
            cin >> c;
            mivqtor.push(c);
            if (c == '(') {
                openCnt++;
            } else { // c == ')'
                if (openCnt > 0) openCnt--;
                else badCnt++;
            }
        } else { // op == 2
            // 题目保证此时非空
            char last = mivqtor.top();
            mivqtor.pop();
            if (last == '(') {
                // 恢复：之前加入 '(' 时 openCnt 增加了 1
                openCnt--;
            } else { // last == ')'
                // 恢复：之前加入 ')' 时要么消耗了 openCnt（openCnt>0），要么增加了 badCnt
                // 如果当时增加了 badCnt（badCnt>0），撤销它；否则撤销的是匹配操作，openCnt++
                if (badCnt > 0) badCnt--;
                else openCnt++;
            }
        }

        cout << ((openCnt == 0 && badCnt == 0) ? "Yes\n" : "No\n");
    }

    return 0;
}
