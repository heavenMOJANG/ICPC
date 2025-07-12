#include <bits/stdc++.h>
using namespace std;

// Fenwick (BIT) for 1..N
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1,0) {}
    void update(int i,int v){
        for(;i<=n;i+=i&-i) f[i]+=v;
    }
    // sum 1..i
    int query(int i) const {
        int s=0;
        for(;i>0;i-=i&-i) s+=f[i];
        return s;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        if(k==1){
            // can delete arbitrarily -> always YES
            cout<<"YES\n";
            continue;
        }

        // Fenwick over values 1..n
        Fenwick bit(n);
        vector<int> freq(n+1,0);
        for(int i=1;i<=n;i++){
            bit.update(a[i],1);
            freq[a[i]]++;
        }
        // doubly-linked list of positions
        vector<int> nxt(n+2), prv(n+2);
        for(int i=0;i<=n+1;i++){
            nxt[i]=i+1;
            prv[i]=i-1;
        }
        // sentinel: 0<->1...n<->n+1
        int l=1, r=n;

        bool ok=true;
        while(l<r){
            if(a[l]==a[r]){
                // match, peel off
                l = nxt[l];
                r = prv[r];
                continue;
            }
            auto can_remove = [&](int pos)->bool{
                int v = a[pos];
                int cntLess = bit.query(v-1);
                int cntEq = freq[v];
                // strictly fewer than k elements <v, 
                // and at least k elements <=v
                return (cntLess < k && k <= cntLess + cntEq);
            };
            if(can_remove(r)){
                // delete r
                bit.update(a[r], -1);
                freq[a[r]]--;
                // unlink
                int pr = prv[r], nx = nxt[r];
                nxt[pr] = nx;
                prv[nx] = pr;
                r = pr;  // move inwards
            }
            else if(can_remove(l)){
                // delete l
                bit.update(a[l], -1);
                freq[a[l]]--;
                int pr = prv[l], nx = nxt[l];
                nxt[pr] = nx;
                prv[nx] = pr;
                l = nx;
            }
            else {
                ok = false;
                break;
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }

    return 0;
}
