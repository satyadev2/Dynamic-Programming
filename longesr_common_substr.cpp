#include <bits/stdc++.h>
using namespace std;

int solve(string text1, string text2, int n, int m)
{
    int ans = 0;

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (text1[j - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main()
{
    string x;
    string y;
    cin >> x;
    cin >> y;
    int n = x.size();
    int m = y.size();
    cout << solve(x, y, n, m);
}
