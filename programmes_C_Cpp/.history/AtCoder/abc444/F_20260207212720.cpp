#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll M;
vector<ll> A;

// Helper to count leaves if we split L until all parts are < 2X
// Returns pair<number of leaves, sum of lengths of leaves>
// Actually we just need number of leaves for broad check
ll count_efficient_leaves(ll L, ll X) {
    if (L < X) return 0;
    if (L < 2 * X) return 1;
    // Find d such that L / 2^d < 2X
    // We want smallest d such that floor(L / 2^d) < 2X
    // floor(L/2^d) < 2X <=> L/2^d < 2X <=> L < 2X * 2^d <=> L/2X < 2^d
    // So 2^d > L/2X.
    // d > log2(L/2X).
    // Let's use loop since log2 can be tricky with large numbers and precision.
    // L <= 10^9, so d is small (< 60).
    // Or just 64 - __builtin_clzll(L / (2*X)) ?
    // L/2X can be 0 if L < 2X.
    
    // Optimization: find d
    ll ratio = L / (2 * X);
    int d = 0;
    if (ratio > 0) {
        d = 64 - __builtin_clzll(ratio);
        // Sometimes need +1?
        // If ratio = 1 (L=2X..3X), d=1. Correct. 2^1=2.
        // If ratio = 0 (L < 2X), d=0. Correct.
    }
    
    // Check if d is enough
    ll p2 = 1LL << d;
    ll q = L / p2;
    // q must be < 2X.
    // Is it possible q >= 2X? Use d+1 then?
    // ratio = L/2X. 2^d > ratio.
    // L/2^d < L/ratio = 2X. So q < 2X holds.
    
    ll r = L % p2;
    // Leaves are:
    // (p2 - r) nodes of size q
    // r nodes of size q+1
    
    ll cnt = 0;
    // If q >= X, counts += (p2 - r)
    if (q >= X) cnt += (p2 - r);
    
    // If q+1 >= X, counts += r
    // Actually q+1 could be 2X? NO, q < 2X, so q+1 <= 2X.
    // If q+1 == 2X, these split further into 2 leaves.
    // q < 2X implies q <= 2X - 1.
    // If q = 2X - 1, then q+1 = 2X.
    if (q + 1 == 2 * X) {
        cnt += r * 2;
    } else if (q + 1 >= X) {
        cnt += r;
    }
    
    return cnt;
}

// Generate actual leaves
void get_leaves(ll L, ll X, vector<ll>& leaves) {
    if (L < X) return;
    if (L < 2 * X) {
        leaves.push_back(L);
        return;
    }
    get_leaves(L / 2, X, leaves);
    get_leaves((L + 1) / 2, X, leaves);
}

bool check(ll X) {
    ll target_good = (N + M + 1) / 2;
    ll bad_capacity = 0;
    vector<ll> good_sources;
    
    for (ll a : A) {
        if (a < X) {
            bad_capacity += (a - 1);
        } else {
            good_sources.push_back(a);
        }
    }
    
    // Quick Check: Potential good sticks
    ll total_efficient = 0;
    bool overflow = false;
    for (ll a : good_sources) {
        ll c = count_efficient_leaves(a, X);
        total_efficient += c; // c is actually efficient count. Cost is c-1 ops.
        // But total_efficient here tracks total *count* of leaves.
        // Ops used for this tree is (c - 1).
        // If sum(c - 1) > M, we are good.
        if (total_efficient > N + M + 2) { // just sufficiently large limit
            overflow = true;
            break;
        }
    }
    
    // Total ops needed for full expansion = total_leaves - good_sources.size()
    // Let's refine.
    ll total_leaves_count = 0;
    if (overflow) {
        // We have enough production capacity.
        // Max useful M is used.
        // Suppose we just greedily perform operations to generate good sticks.
        // Each op adds 1 stick.
        // Initial good sticks = good_sources.size().
        // We can add at most M sticks.
        // If capacity allows adding M sticks, result = initial + M.
        // However, we need to know if we hit limit.
        // Since we overflowed N+M, we definitely have enough capacity to use all M ops.
        
        // Wait, check specific logic:
        // We need to answer if median >= X.
        // This means (Initial Good) + min(Available Splits, M) >= target?
        // Note: each efficient split increases count of good sticks by 1.
        // If we have enough candidate splits to perform M operations, we get Base + M good sticks.
        // Base + M >= (N+M+1)/2 is usually true since Base >= 0?
        // Wait. (N+M+1)/2. Approx (N+M)/2.
        // Base + M >= (N+M)/2 <=> 2*Base + 2M >= N + M <=> 2*Base + M >= N.
        // Since M >= 1, and usually Base is huge?
        // Not necessarily. If Base=0 (no >= X initially), impossible.
        // But here we entered "overflow" which implies sum(leaves) is huge.
        // So we definitely have enough capacity to do M ops.
        // So result good count = good_sources.size() + M.
        // We check if this >= target_good.
        return (good_sources.size() + M) >= target_good; 
    }
    
    // If not overflow, we might calculate exactly.
    // Ops needed to reach full leave set:
    // ops_req = sum(leaves(a) - 1 for a in good_sources)
    //         = total_efficient_leaves - good_sources.size()
    
    // Re-sum total_efficient precisely
    ll total_efficient_sum = 0;
    for (ll a : good_sources) {
        total_efficient_sum += count_efficient_leaves(a, X);
    }
    
    ll ops_req = total_efficient_sum - good_sources.size();
    
    if (ops_req >= M) {
        // We can perform M operations efficiently.
        // Each op adds 1 good stick.
        // Final good = Base + M.
        return (good_sources.size() + M) >= target_good;
    }
    
    // If ops_req < M, we perform all efficient ops.
    // We reach 'total_efficient_sum' good sticks.
    // Remaining ops to waste: rem = M - ops_req.
    ll rem = M - ops_req;
    
    if (rem <= bad_capacity) {
        // We can waste all remaining ops on bad sticks.
        return total_efficient_sum >= target_good;
    }
    
    // We need to waste more. Must sacrifice good leaves.
    ll waste_needed = rem - bad_capacity;
    
    // Collect all leaves to find largest ones to sacrifice
    vector<ll> all_leaves;
    all_leaves.reserve(total_efficient_sum);
    for (ll a : good_sources) {
        get_leaves(a, X, all_leaves);
    }
    
    sort(all_leaves.rbegin(), all_leaves.rend());
    
    ll sacrificed = 0;
    ll absorbed = 0;
    
    for (ll leaf : all_leaves) {
        absorbed += (leaf - 1);
        sacrificed++;
        if (absorbed >= waste_needed) break;
    }
    
    if (absorbed < waste_needed) {
        // Cannot even waste enough ops by sacrificing everything?
        // This implies constraints were tighter than sum(A_i).
        // But problem guarantees M <= sum(A_i) - N.
        // So we should be able to waste everything eventually.
        // However, if we sacrifice ALL leaves, we have 0 good sticks.
        // 0 < target_good (since target >= 1).
        return false;
    }
    
    return (total_efficient_sum - sacrificed) >= target_good;
}


void solve() {
    cin >> N >> M;
    A.resize(N);
    ll sum_A = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum_A += A[i];
    }
    
    ll low = 1, high = 1e9 + 7; 
    // Upper bound can be max(A_i) or slightly more? 
    // Actually if we simply cut everything 1e9, possible?
    // Max median is limited by sum_A / (N+M)? Not really strict bound but useful.
    // 1e9 is safe.
    
    ll ans = 1;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (mid == 0) { low = 1; continue; } // safety
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}