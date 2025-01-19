#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<long long>> restore_grid(int n, int m, string s, vector<vector<long long>> grid) {
    // Determine the path cells
    vector<pair<int, int>> path_cells;
    int i = 0, j = 0;
    for (char step : s) {
        path_cells.push_back({i, j});
        if (step == 'D') {
            i++;
        } else {
            j++;
        }
    }
    path_cells.push_back({i, j});

    // Calculate the sum of non-path cells for each row and column
    vector<long long> row_sum(n, 0);
    vector<long long> col_sum(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (find(path_cells.begin(), path_cells.end(), make_pair(i, j)) == path_cells.end()) {
                row_sum[i] += grid[i][j];
                col_sum[j] += grid[i][j];
            }
        }
    }

    // Determine the common sum x
    long long x = max(*max_element(row_sum.begin(), row_sum.end()),
                      *max_element(col_sum.begin(), col_sum.end()));

    // Assign new altitudes to path cells
    for (auto cell : path_cells) {
        int i = cell.first;
        int j = cell.second;
        grid[i][j] = x - row_sum[i] - col_sum[j];
    }

    return grid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vector<long long>> grid(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        vector<vector<long long>> restored_grid = restore_grid(n, m, s, grid);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << restored_grid[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}