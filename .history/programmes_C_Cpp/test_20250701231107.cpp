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
        int m = 0;
        for(char c : s) if(c == '1') ++m;

        // 1) If Alice can clear all 1's immediately:
        if(m <= k) {
            cout << "Alice\n";
        }
        // 2) If there's enough "room" (n > 2k), Bob can always play disjointly:
        else if(n > 2*k) {
            cout << "Bob\n";
        }
        // 3) Otherwise, Alice will eventually win by exhausting Bob's overlap:
        else {
            cout << "Alice\n";
        }
    }
    return 0;
}
