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

        // 1) prefMin[i] = min of a[0..i]
        vector<int> prefMin(n);
        prefMin[0] = a[0];
        for (int i = 1; i < n; i++)
            prefMin[i] = min(prefMin[i-1], a[i]);

        // 2) sufMax[i] = max of a[i..n-1]
        vector<int> sufMax(n);
        sufMax[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--)
            sufMax[i] = max(sufMax[i+1], a[i]);

        // 3) prevGreater[i]: last j<i with a[j]>a[i], or -1
        vector<int> prevGreater(n, -1);
        {
            stack<int> st;  // will store indices in strictly decreasing a[]
            for (int i = 0; i < n; i++) {
                while (!st.empty() && a[st.top()] <= a[i]) 
                    st.pop();
                prevGreater[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }

        // 4) nextSmaller[i]: first j>i with a[j]<a[i], or n
        vector<int> nextSmaller(n, n);
        {
            stack<int> st;  // will store indices in strictly increasing a[]
            for (int i = n-1; i >= 0; i--) {
                while (!st.empty() && a[st.top()] >= a[i]) 
                    st.pop();
                nextSmaller[i] = st.empty() ? n : st.top();
                st.push(i);
            }
        }

        // now build answer
        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            bool ok = false;

            // (A) prefix‑first then suffix:
            //   crush prefix [0..j‑1] down to its min at j‑1, then crush suffix [j..end] to its max
            //   the “j” to choose is exactly nextSmaller[i], because that’s the first place a[j]<a[i]
            //   so we need prefMin[j‑1]==a[i], and sufMax[j] <= a[i]
            int j = nextSmaller[i];
            if (j>0 && prefMin[j-1] == a[i] && (j==n || sufMax[j] <= a[i]))
                ok = true;

            // (B) suffix‑first then prefix:
            //   crush suffix [j..n‑1] to its max at j, then crush prefix [0..j‑1] to its min
            //   here j = prevGreater[i]+1, because that’s the first index at or after which all
            //   suffix values are ≤ a[i]
            if (!ok) {
                j = prevGreater[i] + 1;
                if (j<n && sufMax[j] == a[i] &&
                    (prevGreater[i]<0 || prefMin[prevGreater[i]] >= a[i]))
                    ok = true;
            }

            ans[i] = ok ? '1' : '0';
        }

        cout << ans << "\n";
    }
    return 0;
}
