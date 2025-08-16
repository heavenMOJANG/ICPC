#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<long long> b(n+1);
        for(int i=1; i<=n; i++){
            cin >> b[i];
        }

        // running prefix sum
        long long S = b[1];
        bool ok = true;

        // check for every i>=2: b[i] < sum_{j<i} b[j]
        for(int i=2; i<=n; i++){
            if(b[i] >= S){
                ok = false;
                break;
            }
            S += b[i];
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
