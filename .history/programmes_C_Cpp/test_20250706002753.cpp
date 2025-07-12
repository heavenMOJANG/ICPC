// dp[i][k] = 用前 i 步做了 k 次匹配的所有合法方案权值之和。
// 只要你严格按照下面的转移，就能 AC。

// —— 伪  C++ 代码 —— 
vector<ll> dp(n+1), ndp(n+1);
dp[0] = 1;

for(int i = 1; i <= n; i++){
  fill(ndp.begin(), ndp.end(), 0);

  // pre[k] 存 dp[i-1][k] 对应的“已用过 token 的总标签和”
  // 这样我们就能精确知道，“当前自由 token”在 [1..i] 中
  // 每个点被选中的所有方案的累积标签和。
  vector<ll> pre(n+1);
  // 计算 pre[k]……（这里需要 O(n^2) 的前缀和扫描）

  for(int k = 0; k < i; k++){
    // 1) 跳过：dp[i][k] += dp[i-1][k]
    ndp[k] = (ndp[k] + dp[k]) % m;

    // 2) 匹配：dp[i][k+1] += “所有当前自由 token 的标签和”
    ll freeSum = /* = sum_{p ∈ free} p * dp[i-1][k] */;
    ndp[k+1] = (ndp[k+1] + freeSum) % m;
  }

  dp.swap(ndp);
}
ll ans = accumulate(dp.begin(), dp.end(), 0LL) % m;
