#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int N, Q;

// fast mod operations
ll addmod(ll a, ll b){ a+=b; if(a>=MOD) a-=MOD; return a;}
ll submod(ll a, ll b){ a-=b; if(a<0) a+=MOD; return a;}
ll mulmod(ll a, ll b){ return (a*b)%MOD; }
ll powmod(ll a, ll e=MOD-2){ ll r=1; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1;} return r; }

// factorials for combinations
vector<ll> fact, invfact;
void init_fact(int upto){
    fact.assign(upto+1,0); invfact.assign(upto+1,0);
    fact[0]=1;
    for(int i=1;i<=upto;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[upto]=powmod(fact[upto]);
    for(int i=upto;i>0;i--) invfact[i-1]=invfact[i]*i%MOD;
}
ll C(int n,int k){
    if(n<0 || k<0 || k>n) return 0;
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

// f(n,k) = number of length-n binary strings with k ones and no adjacent ones
// formula: C(n-k+1, k) when valid
ll f_nk(int n,int k){
    if(n<0) return 0;
    if(k<0) return 0;
    int maxk = (n+1)/2;
    if(k>maxk) return 0;
    return C(n - k + 1, k);
}

// g(len, sum, lastbit): number of length-len sequences (no adjacent) with sum ones and last bit fixed
ll g_len_sum_last(int len, int sum, int lastbit){
    if(len<0) return 0;
    if(lastbit==1){
        // last is 1 => reduce: number equals f(len-1, sum-1)
        return f_nk(len-1, sum-1);
    } else {
        // last is 0 => total f(len,sum) minus those with last=1
        ll total = f_nk(len, sum);
        ll last1 = f_nk(len-1, sum-1);
        return submod(total, last1);
    }
}

// w(L,k, left_bit, right_bit) per derivation
ll w_L_k_bits(int L, int k, int leftb, int rightb){
    if(L<0) return 0;
    if(leftb==1){
        // x1 forced 0 -> consider length L-1, sum=k, lastbit = rightb
        return g_len_sum_last(L-1, k, rightb);
    } else {
        // leftb==0: either x1=0 -> reduce len-1 sum=k
        // or x1=1 -> x2=0 forced -> reduce len-2 sum=k-1
        ll a = g_len_sum_last(L-1, k, rightb);
        ll b = g_len_sum_last(L-2, k-1, rightb);
        return addmod(a, b);
    }
}

// 2x2 matrix representation (row-major): mat[r][c], r,c in {0,1}
// We'll store as array of 4: m[0]=00, m[1]=01, m[2]=10, m[3]=11
struct Mat {
    ll m[4];
    Mat(){ m[0]=m[1]=m[2]=m[3]=0; }
    static Mat identity(){
        Mat I; I.m[0]=1; I.m[1]=0; I.m[2]=0; I.m[3]=1; return I;
    }
};
Mat mulMat(const Mat &A, const Mat &B){
    // (A * B) with A,B 2x2: C[i][j] = sum_k A[i][k]*B[k][j]
    Mat C;
    C.m[0] = (A.m[0]*B.m[0] + A.m[1]*B.m[2])%MOD;
    C.m[1] = (A.m[0]*B.m[1] + A.m[1]*B.m[3])%MOD;
    C.m[2] = (A.m[2]*B.m[0] + A.m[3]*B.m[2])%MOD;
    C.m[3] = (A.m[2]*B.m[1] + A.m[3]*B.m[3])%MOD;
    return C;
}

// segment tree over positions 0..N (size N+1 leaves)
struct SegTree {
    int n;
    vector<Mat> seg;
    SegTree(int _n=0){ init(_n); }
    void init(int _n){
        n=1; while(n<_n) n<<=1;
        seg.assign(2*n, Mat::identity());
    }
    void setLeaf(int pos, const Mat &val){
        int p = pos + n;
        seg[p] = val;
        while(p>1){
            p>>=1;
            seg[p] = mulMat(seg[p<<1], seg[p<<1|1]);
        }
    }
    Mat allProd(){ return seg[1]; }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>Q;
    vector<pair<int,int>> queries(Q);
    for(int i=0;i<Q;i++) cin>>queries[i].first>>queries[i].second;

    // precompute factorials upto N+5 for combinations
    init_fact(2*N + 10); // safe upper bound
    // precompute fib-like total counts: fibTotal[len] = number of length-len sequences with no adjacent (all k)
    vector<ll> fib(N+5);
    // fibTotal[0]=1 (empty), fibTotal[1]=2 ("0","1"), fibTotal[n]=fib[n-1]+fib[n-2]
    fib[0]=1;
    if(N>=1) fib[1]=2;
    for(int i=2;i<=N;i++) fib[i] = addmod(fib[i-1], fib[i-2]);

    // map of specified positions: pos -> a_pos. always keep (0 -> 0)
    map<int,int> mp;
    mp[0]=0;

    // segment tree init for positions 0..N
    SegTree st(N+1); // indices 0..N inclusive

    auto computeMatrixForPair = [&](map<int,int>::iterator itL, map<int,int>::iterator itR)->Mat{
        // if itR==end => identity (no segment)
        if(itR==mp.end()) return Mat::identity();
        int p = itL->first;
        int q = itR->first;
        int L = q - p;
        int k = itR->second - itL->second;
        Mat M;
        // M[left][right] where left in {0,1} row, right in {0,1} col
        for(int left=0; left<=1; ++left){
            for(int right=0; right<=1; ++right){
                ll val = 0;
                // if k invalid, w returns 0
                val = w_L_k_bits(L, k, left, right);
                M.m[left*2 + right] = val % MOD;
            }
        }
        return M;
    };

    // helper: update leaf for a given left iterator (leaf index = left->first)
    auto updateLeafForLeftIt = [&](map<int,int>::iterator itL){
        if(itL==mp.end()) return;
        auto itR = itL; ++itR;
        Mat M = computeMatrixForPair(itL, itR);
        st.setLeaf(itL->first, M);
    };

    // initially mp only {0:0}; no pair, so leaf 0 = identity already
    // ensure all other leaves identity (segtree was initialized to identity)

    // function to compute answer from current segtree & mp
    auto computeAnswer = [&]()->ll{
        Mat P = st.allProd(); // product M1*M2*...
        // initial vector [1,0] * P -> simply first row of P
        ll v0 = P.m[0]; // row0 col0
        ll v1 = P.m[1]; // row0 col1
        // suffix from last specified position to N:
        auto itLast = mp.end(); --itLast;
        int lastPos = itLast->first;
        int L = N - lastPos;
        ll ext0, ext1;
        if(L==0){
            ext0 = 1;
            ext1 = 1; // if no suffix, extension count is 1 regardless (no more placements)
        } else {
            ext0 = fib[L]; // total sequences length L
            ext1 = fib[L-1]; // sequences length L with first position forced 0 => reduces to length L-1
        }
        ll ans = ( v0 * ext0 + v1 * ext1 ) % MOD;
        return ans;
    };

    // process queries
    for(auto &qpair: queries){
        int X = qpair.first;
        int Y = qpair.second; // -1 .. X
        auto it = mp.find(X);
        if(Y==-1){
            // delete if exists
            if(it==mp.end()){
                // nothing changes
            } else {
                // will remove it; need to update the leaf of previous left and clear leaf at X
                auto itRemove = it;
                auto itPrev = itRemove;
                --itPrev; // guaranteed exist because mp[0]=0
                auto itNext = itRemove; ++itNext; // may be mp.end()

                // set leaf at prev to prev->next
                Mat newPrevMat = computeMatrixForPair(itPrev, itNext);
                st.setLeaf(itPrev->first, newPrevMat);
                // set leaf at removed pos to identity
                st.setLeaf(itRemove->first, Mat::identity());
                mp.erase(itRemove);
            }
        } else {
            // insert or update
            if(it==mp.end()){
                // insert: need to find neighbors
                auto itNext = mp.lower_bound(X); // first >= X, since X not in mp this is >X or end
                auto itPrev = itNext;
                if(itPrev==mp.begin()){
                    // impossible because mp always contains 0 and X>=1, so OK
                } else --itPrev;
                // insert now
                mp[X]=Y;
                auto itNew = mp.find(X);
                // update leaf at prev: prev -> new
                Mat mPrevNew = computeMatrixForPair(itPrev, itNew);
                st.setLeaf(itPrev->first, mPrevNew);
                // update leaf at new: new -> next
                Mat mNewNext = computeMatrixForPair(itNew, itNext);
                st.setLeaf(itNew->first, mNewNext);
            } else {
                // update existing value mp[X] -> Y
                if(it->second == Y){
                    // no change
                } else {
                    it->second = Y;
                    // update leaf at prev and at X
                    auto itPrev = it;
                    if(itPrev!=mp.begin()) --itPrev; else { /*should not happen since 0 exists*/ }
                    auto itNext = it; ++itNext;
                    Mat mPrev = computeMatrixForPair(itPrev, it);
                    st.setLeaf(itPrev->first, mPrev);
                    Mat mHere = computeMatrixForPair(it, itNext);
                    st.setLeaf(it->first, mHere);
                }
            }
        }
        // after update compute answer and print
        ll ans = computeAnswer();
        cout << ans << '\n';
    }
    return 0;
}
