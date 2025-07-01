#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--){
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> pos;
        for (int i = 0; i < n; i++){
            if (s[i] == '1') pos.push_back(i);
        }
        int m = pos.size();
        // Case 1: Alice wipes out all 1's immediately
        if (m <= k){
            cout << "Alice\n";
            continue;
        }
        // Case 2: all 1's lie within some k-block → Bob can stall forever
        int L = pos.front(), R = pos.back();
        if (R - L + 1 <= k){
            cout << "Bob\n";
        } else {
            // Otherwise Alice eventually wins
            cout << "Alice\n";
        }
    }

    return 0;
}
