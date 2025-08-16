#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    // 1) Find smallest string X = S[j0]
    int j0 = 0;
    for(int i = 1; i < N; i++){
        if(S[i] < S[j0]) j0 = i;
    }
    const string& X = S[j0];

    // 2) Among all i, pick i0 minimizing S[i] + X
    int i0 = 0;
    string best = S[0] + X;
    for(int i = 1; i < N; i++){
        string t = S[i] + X;
        if(t < best){
            best = t;
            i0 = i;
        }
    }

    // 3) Build the answer by repeating (i0, j0)
    string ans;
    ans.reserve((long long)K * X.size());  // rough reserve
    int pairs = K / 2;
    for(int t = 0; t < pairs; t++){
        ans += S[i0];
        ans += X;         // = S[j0]
    }
    if(K & 1){
        ans += S[i0];
    }

    cout << ans << "\n";
    return 0;
}
