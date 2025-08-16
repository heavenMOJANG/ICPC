#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAX_A = 300;
const int DP_SIZE = MAX_A * 2; // 安全マージンを持たせたDPテーブルのサイズ

int main() {
    // 高速な入出力
    cin.tie(nullptr)->sync_with_stdio(false);

    long long n;
    int m;
    cin >> n >> m;

    vector<pair<int, int>> exchanges(m);
    for (int i = 0; i < m; ++i) {
        cin >> exchanges[i].first >> exchanges[i].second;
    }

    // --- ステップ1: 動的計画法による事前計算 ---
    vector<long long> dp(DP_SIZE + 1, 0);

    for (int j = 1; j <= DP_SIZE; ++j) {
        // 何も交換しない場合、追加で飲めるのは0本
        dp[j] = 0; 
        // 可能な全ての交換を試す
        for (const auto& ex : exchanges) {
            int a = ex.first;
            int b = ex.second;
            if (j >= a) {
                // 交換後、b本飲み、空き瓶は j - a + b 本になる
                // その状態からさらに飲める本数 dp[j - a + b] を足す
                dp[j] = max(dp[j], (long long)b + dp[j - a + b]);
            }
        }
    }

    // --- ステップ2: メイン計算 ---
    long long total_drinks = n;
    long long bottles = n;

    // 貪欲フェーズ
    if (bottles >= DP_SIZE) {
        // 最も効率の良い交換を見つける
        pair<int, int> best_exchange = {-1, -1};
        // B/(A-B) の最大化は B_1*(A_2-B_2) > B_2*(A_1-B_1) の比較で行う
        for (const auto& ex : exchanges) {
            if (best_exchange.first == -1) {
                best_exchange = ex;
            } else {
                long long current_a = best_exchange.first;
                long long current_b = best_exchange.second;
                long long new_a = ex.first;
                long long new_b = ex.second;
                if (new_b * (current_a - current_b) > current_b * (new_a - new_b)) {
                    best_exchange = ex;
                }
            }
        }

        long long best_a = best_exchange.first;
        long long best_b = best_exchange.second;
        long long delta = best_a - best_b;

        // DPテーブルの範囲に入るまでまとめて交換する
        if (delta > 0) {
            long long num_exchanges = (bottles - (DP_SIZE -1)) / delta;
            if (num_exchanges > 0) {
                total_drinks += num_exchanges * best_b;
                bottles -= num_exchanges * delta;
            }
        }
    }

    // DPフェーズ
    // 貪欲フェーズの後、残った空き瓶で飲める最大本数を加算
    if (bottles <= DP_SIZE) {
        total_drinks += dp[bottles];
    }

    cout << total_drinks << endl;

    return 0;
}