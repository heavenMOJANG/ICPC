#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T;
    while(T--){
        int N; string S;
        cin >> N >> S;
        vector<int> rightRun(N, 0), leftRun(N, 0);

        // rightRun[i]: number of consecutive 'R' ending at S[i-1] (i.e. between i-1 and i)
        for(int i=1;i<N;i++){
            if(S[i-1]=='R') rightRun[i] = rightRun[i-1] + 1;
            else rightRun[i] = 0;
        }
        // leftRun[i]: number of consecutive 'L' starting at S[i] (i.e. between i and i+1)
        for(int i=N-2;i>=0;i--){
            if(S[i]=='L') leftRun[i] = leftRun[i+1] + 1;
            else leftRun[i] = 0;
        }

        for(int i=0;i<N;i++){
            int left = (i-1 >= 0 ? rightRun[i-1] : 0);
            int right = (i < N-1 ? leftRun[i] : 0);
            cout << (left + right + 1) << (i+1 < N ? ' ' : '\n');
        }
    }
    return 0;
}
