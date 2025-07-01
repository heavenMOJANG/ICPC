#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int a[510][510];
void set_1a(int n)
{
  const int nn = (n - 1) | 1;
  int x = nn / 2u, y = x, k = 0;
  for (int len = 1; len < nn; len += 2) {
    for (int j = 0; j < len; ++j) a[x][y++] = ++k;
    for (int j = 0; j < len; ++j) a[x++][y] = ++k;
    for (int j = 0; j <= len; ++j) a[x][y--] = ++k;
    for (int j = 0; j <= len; ++j) a[x--][y] = ++k;
  }
  
  for(int j = 0; j < nn; ++j) a[0][j] = ++k;
  if ((n & 1) == 0) {
    for (int j = 0; j < nn; ++j) a[j][nn] = ++k;
    for (int j = nn; j >= 0; --j) a[nn][j] = ++k;  
  }
}
void set_1b(int n)
{
  int len = 0, k = 0, x = (n - 1) / 2u, y = x;
  while (1) {
    ++len;
    for (int j = 0; j < len; ++j) a[x][y++] = ++k;
    if (len == n) break;
    for (int j = 0; j < len; ++j) a[x++][y] = ++k;

    ++len;
    for (int j = 0; j < len; ++j) a[x][y--] = ++k;
    if (len == n) break;
    for (int j = 0; j < len; ++j) a[x--][y] = ++k;    
  }
}
void set_2(int n)
{
  const int nn = (n - 1) | 1;
  int k = 0;
  for (int i = nn / 2u; i > 0; --i) {
    const int C = nn - i;
    for (int j = i; j < C; ++j) a[i][j] = ++k;    
    for (int j = i; j < C; ++j) a[j][C] = ++k;    
    for (int j = C; j >= i; --j) a[C][j] = ++k;    
    for (int j = C; j >= i; --j) a[j][i - 1] = ++k;
  }
  
  for(int j = 0; j < nn; ++j) a[0][j] = ++k;
  if ((n & 1) == 0) {
    for (int j = 0; j < nn; ++j) a[j][nn] = ++k;
    for (int j = nn; j >= 0; --j) a[nn][j] = ++k;  
  }
}
void solve() {
    int n; cin >> n;
    set_1b(n);
    for (int i{}; i < n; ++ i)
        for (int j{}; j < n; ++ j) cout << a[i][j] - 1 << " \n"[j == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}