#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // 步骤 1: 预处理，移除作为其他字符串子串的字符串
    vector<string> patterns;
    vector<bool> is_substring(N, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            // 如果 S[i] 是 S[j] 的子串 (且 S[i] != S[j])
            if (S[j].find(S[i]) != string::npos) {
                is_substring[i] = true;
                break;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!is_substring[i]) {
            patterns.push_back(S[i]);
        }
    }
    
    int M = patterns.size();
    if (M == 0) {
        // 如果没有必须包含的模式，任何长度为L的字符串都有效
        long long ans = 1;
        for (int i = 0; i < L; ++i) {
            ans = (ans * 26) % MOD;
        }
        cout << ans << endl;
        return 0;
    }

    // 步骤 2: 构建 Aho-Corasick 自动机
    vector<vector<int>> go;
    vector<int> link;
    vector<int> output_mask;

    // 初始化根节点
    go.emplace_back(26, 0);
    link.push_back(0);
    output_mask.push_back(0);
    int nodes = 1;

    // 将模式插入到Trie中
    for (int i = 0; i < M; ++i) {
        int v = 0;
        for (char ch : patterns[i]) {
            int c = ch - 'a';
            if (go[v][c] == 0) {
                go[v][c] = nodes++;
                go.emplace_back(26, 0);
                link.push_back(0);
                output_mask.push_back(0);
            }
            v = go[v][c];
        }
        output_mask[v] |= (1 << i);
    }

    // 使用BFS构建失败链接和完整的状态转移
    queue<int> q;
    for (int c = 0; c < 26; ++c) {
        if (go[0][c]) {
            q.push(go[0][c]);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int c = 0; c < 26; ++c) {
            if (go[v][c]) {
                link[go[v][c]] = go[link[v]][c];
                // 将失败链接节点的输出掩码合并到当前节点
                output_mask[go[v][c]] |= output_mask[link[go[v][c]]];
                q.push(go[v][c]);
            } else {
                go[v][c] = go[link[v]][c];
            }
        }
    }

    // 步骤 3: 动态规划
    int num_states = nodes;
    vector<vector<long long>> dp(num_states, vector<long long>(1 << M, 0));
    dp[0][0] = 1; // 长度为0的空字符串，在状态0，掩码为0

    for (int i = 0; i < L; ++i) {
        vector<vector<long long>> next_dp(num_states, vector<long long>(1 << M, 0));
        for (int j = 0; j < num_states; ++j) {
            for (int mask = 0; mask < (1 << M); ++mask) {
                if (dp[j][mask] == 0) continue;

                for (int c = 0; c < 26; ++c) {
                    int next_state = go[j][c];
                    int next_mask = mask | output_mask[next_state];
                    next_dp[next_state][next_mask] = (next_dp[next_state][next_mask] + dp[j][mask]) % MOD;
                }
            }
        }
        dp = next_dp;
    }

    // 步骤 4: 计算最终结果
    long long ans = 0;
    int final_mask = (1 << M) - 1;
    for (int j = 0; j < num_states; ++j) {
        ans = (ans + dp[j][final_mask]) % MOD;
    }

    cout << ans << endl;

    return 0;
}