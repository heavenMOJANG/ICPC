#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> B(M);
    vector<ll> C(M);
    ll totalC = 0;
    for (int j = 0; j < M; ++j) {
        cin >> B[j] >> C[j];
        totalC += C[j];
    }

    // 估算节点数： source + M song nodes + sum(B_j) position nodes + N idol nodes + sink
    int sumB = 0;
    for (int j = 0; j < M; ++j) sumB += B[j];

    int source = 0;
    int songBase = 1;                        // song j => node songBase + j
    int posBase = songBase + M;              // positions enumerated from posBase ... posBase+sumB-1
    int idolBase = posBase + sumB;           // idol i => node idolBase + i
    int sink = idolBase + N;

    int totNodes = sink + 1;
    atcoder::mf_graph<ll> mf(totNodes);

    // INF large enough (sumC + something). Use 1e18/4 as safe bound.
    const ll INF = (1LL<<60);

    // source -> song with capacity C[j]
    for (int j = 0; j < M; ++j) {
        if (C[j] > 0) mf.add_edge(source, songBase + j, C[j]);
        // if C[j] == 0, adding zero-capacity edge is harmless but unnecessary
    }

    // create position nodes and edges song -> each position with INF
    int posId = 0;
    for (int j = 0; j < M; ++j) {
        for (int k = 0; k < B[j]; ++k) {
            int posNode = posBase + posId++;
            // If song is selected (i.e., we keep s->song edge), then we must also keep these positions:
            mf.add_edge(songBase + j, posNode, INF);
            // connect this position to every idol with capacity 1 (an idol can fill at most one position per song)
            for (int i = 0; i < N; ++i) {
                mf.add_edge(posNode, idolBase + i, 1);
            }
        }
    }

    // idol -> sink with capacity A[i]
    for (int i = 0; i < N; ++i) {
        if (A[i] > 0) mf.add_edge(idolBase + i, sink, A[i]);
    }

    // compute maxflow = mincut capacity
    ll flow = mf.flow(source, sink);

    // answer = totalC - mincut
    ll answer = totalC - flow;
    cout << answer << '\n';
    return 0;
}
