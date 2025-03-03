#include<bits/stdc++.h>
using namespace std;
int N, K, S, ans, score_final, score_extra, mark[105]={0};
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    cin >> N >> K >> S;
    for (int i = 1; i <= N; i++)
    {
        int a, b; cin >> a >> b;
        if (a >= 80)
        {
            if (b >= S)
            {
                ans++;
            }
            else if (mark[a] < K)
            {
                ans++;
                mark[a]++;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}