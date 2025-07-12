#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<vector<int>> adj(N+1);
        for(int i = 0; i < N-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS from 1 to compute dist[]
        vector<int> dist(N+1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int w: adj[u]){
                if(dist[w] == -1){
                    dist[w] = dist[u] + 1;
                    q.push(w);
                }
            }
        }

        // Output answers for 2..N
        for(int v = 2; v <= N; v++){
            if(dist[v] % K == 0)
                cout << (dist[v] / K);
            else
                cout << -1;
            if(v < N) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
