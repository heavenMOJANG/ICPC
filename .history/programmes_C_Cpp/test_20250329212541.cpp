#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    // 检查字符映射一致性
    int s_map[26];
    fill(s_map, s_map + 26, -1);
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        char s_char = S[i];
        char t_char = T[i];
        int s = s_char - 'a';
        int t = t_char - 'a';
        if (s_map[s] != -1) {
            if (s_map[s] != t) {
                possible = false;
                break;
            }
        } else {
            s_map[s] = t;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    // 构建映射关系
    int mapping[26];
    bool has_mapping[26] = {false};
    for (int s = 0; s < 26; ++s) {
        if (s_map[s] != -1 && s_map[s] != s) {
            mapping[s] = s_map[s];
            has_mapping[s] = true;
        }
    }

    bool visited[26] = {false};
    int total_ops = 0;

    // 检测环并计算操作次数
    for (int s = 0; s < 26; ++s) {
        if (has_mapping[s] && !visited[s]) {
            vector<int> path;
            int current = s;
            while (true) {
                if (visited[current]) {
                    auto it = find(path.begin(), path.end(), current);
                    if (it != path.end()) {
                        cout << -1 << endl;
                        return 0;
                    } else {
                        total_ops += path.size() - 1;
                        for (int node : path) {
                            visited[node] = true;
                        }
                        break;
                    }
                } else {
                    visited[current] = true;
                    path.push_back(current);
                    if (!has_mapping[current]) {
                        total_ops += path.size() - 1;
                        for (int node : path) {
                            visited[node] = true;
                        }
                        break;
                    }
                    current = mapping[current];
                }
            }
        }
    }

    cout << total_ops << endl;
    return 0;
}