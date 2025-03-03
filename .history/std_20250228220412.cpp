#include<bits/stdc++.h>
using namespace std;
int N, K, S, ans, score_final, score_extra, mark[105]={0};
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("1.in", "r", stdin);
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
    freopen("1.out", "w", stdout);
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
【样例输入】
10 2 90
80 60
80 50
80 90
80 80
85 40
70 100
79 100
95 0
85 60
85 60

【样例输出】
6
*/