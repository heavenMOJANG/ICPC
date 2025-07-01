#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Point {
    int x, y;
};
struct Edge {
    int dist;
    int u, v;

    bool operator<(const Edge& other) const {
        return dist < other.dist;
    }
};
struct DSU {
    vector<int> parent;
    int num_components;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        num_components = n;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            num_components--;
        }
    }
};
int manhattan_distance(const Point& p1, const Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N_initial, Q;
    cin >> N_initial >> Q;

    vector<Point> coords(N_initial + 1);
    for (int i = 1; i <= N_initial; ++i) {
        cin >> coords[i].x >> coords[i].y;
    }

    int current_n = N_initial;
    DSU dsu(N_initial + Q);
    vector<Edge> all_edges;
    bool dirty = true; // Flag to indicate if edges need recalculation
    size_t edge_ptr = 0;


    for (int q = 0; q < Q; ++q) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;
            current_n++;
            coords.push_back({a, b});
            // New vertex is in its own component
            dsu.parent.push_back(current_n);
            dsu.parent[current_n] = current_n;
            dsu.num_components++;
            dirty = true;
        } else if (type == 2) {
            if (dsu.num_components == 1) {
                cout << -1 << "\n";
                continue;
            }

            if (dirty) {
                all_edges.clear();
                for (int i = 1; i <= current_n; ++i) {
                    for (int j = i + 1; j <= current_n; ++j) {
                        all_edges.push_back({manhattan_distance(coords[i], coords[j]), i, j});
                    }
                }
                sort(all_edges.begin(), all_edges.end());
                edge_ptr = 0;
                dirty = false;
            }
            int min_dist = -1;
            size_t first_merge_idx = -1;
            for (size_t i = edge_ptr; i < all_edges.size(); ++i) {
                const auto& edge = all_edges[i];
                if (dsu.find(edge.u) != dsu.find(edge.v)) {
                    min_dist = edge.dist;
                    first_merge_idx = i;
                    break;
                }
            }
            cout << min_dist << "\n";
            if (min_dist != -1) {
                for (size_t i = first_merge_idx; i < all_edges.size(); ++i) {
                    const auto& edge = all_edges[i];
                    if (edge.dist > min_dist) {
                        edge_ptr = i;
                        break;
                    }
                    if (edge.dist == min_dist) {
                        dsu.unite(edge.u, edge.v);
                    }
                     if (i == all_edges.size() - 1) {
                        edge_ptr = all_edges.size();
                    }
                }
            }

        } else { // type == 3
            int u, v;
            cin >> u >> v;
            if (dsu.find(u) == dsu.find(v)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}