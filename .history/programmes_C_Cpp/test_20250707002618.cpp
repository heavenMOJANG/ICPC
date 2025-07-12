#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    int N, LOG;
    vector<vector<int>> st;
    vector<int> lg;
    RMQ(const vector<int>& a) {
        N = a.size();
        LOG = 32 - __builtin_clz(N);
        st.assign(LOG, vector<int>(N));
        lg.assign(N+1,0);
        for(int i=2;i<=N;i++) lg[i] = lg[i/2]+1;
        st[0] = a;
        for(int k=1;k<LOG;k++){
            for(int i=0;i + (1<<k) <= N; i++){
                st[k][i] = max(st[k-1][i], st[k-1][i + (1<<(k-1))]);
            }
        }
    }
    // max on [L..R], 0-based, inclusive
    int query(int L, int R){
        int k = lg[R-L+1];
        return max(st[k][L], st[k][R - (1<<k) + 1]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) 
            cin >> a[i];

        // k==1 → you can delete any element freely → always OK
        if(k==1){
            cout << "YES\n";
            continue;
        }

        RMQ rmq(a);
        int l = 0, r = n-1;
        bool ok = false;
        while(true){
            // matched or crossed → success
            if(l >= r){
                ok = true;
                break;
            }
            // if ends match, just absorb them
            if(a[l] == a[r]){
                l++; 
                r--;
                continue;
            }
            // otherwise try to delete left end
            bool delL = false, delR = false;
            if(r - l + 1 >= k){
                // window [l..l+k-1] must lie within [l..r]
                if(r >= l + k - 1 && rmq.query(l, l + k - 1) == a[l])
                    delL = true;
            }
            // try to delete right end
            if(r - l + 1 >= k){
                // window [r-k+1..r] must lie within [l..r]
                if(l <= r - k + 1 && rmq.query(r - k + 1, r) == a[r])
                    delR = true;
            }
            if(delL){
                l++;
            }
            else if(delR){
                r--;
            }
            else{
                // cannot delete either end → fail
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
