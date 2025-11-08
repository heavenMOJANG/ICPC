#include <iostream>
#include <vector>
#include <numeric>
#include <atcoder/mincostflow>

// 使用 long long 以避免整数溢出
using ll = long long;

int main() {
    // 加速 I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<ll> B(M), C(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i] >> C[i];
    }

    // --- 网络流模型构建 ---

    // 节点编号:
    // 源点 s: 0
    // 偶像节点: 1 to N
    // 歌曲节点: N + 1 to N + M
    // 汇点 t: N + M + 1
    int s = 0;
    int t = N + M + 1;
    int num_nodes = N + M + 2;

    // 创建一个 mcf_graph 对象
    // atcoder::mcf_graph<capacity_type, cost_type> graph(num_nodes);
    atcoder::mcf_graph<int, ll> graph(num_nodes);

    // 1. 添加偶像供应边: s -> idol_i
    for (int i = 0; i < N; ++i) {
        int idol_node = i + 1;
        graph.add_edge(s, idol_node, A[i], 0);
    }

    // 2. 添加歌曲需求边: song_j -> t
    for (int j = 0; j < M; ++j) {
        int song_node = N + j + 1;
        graph.add_edge(song_node, t, B[j], 0);
    }

    // 3. 添加分配与收益边: idol_i -> song_j
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int idol_node = i + 1;
            int song_node = N + j + 1;
            // 将收益 C[j] 建模为成本 -C[j]
            graph.add_edge(idol_node, song_node, 1, -C[j]);
        }
    }

    // --- 求解并输出结果 ---

    // 计算从 s 到 t 的最小费用流
    // 我们不需要限制总流量，算法会自动找到最优的流量
    auto result = graph.flow(s, t);

    // result.second 是最小总成本
    // 因为我们将收益建模为负成本，所以要取其相反数
    ll max_excitement = -result.second;

    std::cout << max_excitement << std::endl;

    return 0;
}