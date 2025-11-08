#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> fl(N + 1, 0);
        fl[N] = 0;
        for (int k = N - 1; k >= 1; k--) {
            if (S[k - 1] == 'R') {
                fl[k] = 0;
            } else {
                fl[k] = 1 + fl[k + 1];
            }
        }
        vector<int> fr(N + 1, 0);
        fr[N] = 0;
        for (int k = N - 1; k >= 1; k--) {
            if (S[k - 1] == 'L') {
                fr[k] = 0;
            } else {
                fr[k] = 1 + fr[k + 1];
            }
        }
        vector<int> gl(N + 1, 0);
        gl[1] = 0;
        for (int k = 2; k <= N; k++) {
            if (S[k - 2] == 'R') {
                gl[k] = 1 + gl[k - 1];
            } else {
                gl[k] = 0;
            }
        }
        vector<int> gr(N + 1, 0);
        gr[1] = 0;
        for (int k = 2; k <= N; k++) {
            if (S[k - 2] == 'L') {
                gr[k] = 1 + gr[k - 1];
            } else {
                gr[k] = 0;
            }
        }
        vector<int> Ls(N + 1, 0);
        vector<int> Rs(N + 1, 0);
        for (int k = 1; k <= N; k++) {
            int forced_l = gl[k] + fl[k];
            Ls[k] = 1 + forced_l;
            int forced_r = gr[k] + fr[k];
            Rs[k] = N - forced_r;
        }
        vector<int> diff(N + 2, 0);
        for (int k = 1; k <= N; k++) {
            int l = Ls[k];
            int r = Rs[k];
            if (l <= r) {
                diff[l]++;
                if (r + 1 <= N) {
                    diff[r + 1]--;
                }
            }
        }
        int cur = 0;
        for (int j = 1; j <= N; j++) {
            cur += diff[j];
            cout << cur;
            if (j < N) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
    }
    return 0;
}