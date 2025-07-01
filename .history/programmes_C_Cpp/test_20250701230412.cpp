#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n; 
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        // 1) 前缀最小
        vector<int> prefMin(n);
        prefMin[0] = a[0];
        for (int i = 1; i < n; i++)
            prefMin[i] = min(prefMin[i-1], a[i]);

        // 2) 后缀最大
        vector<int> sufMax(n);
        sufMax[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--)
            sufMax[i] = max(sufMax[i+1], a[i]);

        // 3) prevGreater：左侧第一个 > a[i]
        vector<int> prevGreater(n, -1);
        {
            stack<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && a[st.top()] <= a[i]) 
                    st.pop();
                prevGreater[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }

        // 4) nextSmaller：右侧第一个 < a[i]
        vector<int> nextSmaller(n, n);
        {
            stack<int> st;
            for (int i = n-1; i >= 0; i--) {
                while (!st.empty() && a[st.top()] >= a[i]) 
                    st.pop();
                nextSmaller[i] = st.empty() ? n : st.top();
                st.push(i);
            }
        }

        // 5) 组合判断
        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            bool ok = false;

            // A) 先前缀，再后缀
            int j = nextSmaller[i];
            if (j > 0 
                && prefMin[j-1] == a[i] 
                && (j == n || sufMax[j] <= a[i])) 
            {
                ok = true;
            }

            // B) 先后缀，再前缀
            if (!ok) {
                j = prevGreater[i] + 1;
                if (j < n 
                    && sufMax[j] == a[i] 
                    && (prevGreater[i] < 0 || prefMin[prevGreater[i]] >= a[i])) 
                {
                    ok = true;
                }
            }

            ans[i] = ok ? '1' : '0';
        }

        cout << ans << "\n";
    }
    return 0;
}
