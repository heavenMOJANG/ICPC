#include<bits/stdc++.h>
using namespace std;
int N, K, S, ans, score_final, score_extra, mark[105]={0};    //ans记录答案，mark记录每一种分数的出现次数
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
            else if (mark[a] < K)     //该分数a的出现次数小于K时，说明可以将该分数放入下一批次中。
            {
                ans++;
                mark[a]++;
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}